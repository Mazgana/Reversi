#include "RemoteGame.h"

RemoteGame::RemoteGame() {
	displayer = new ConsoleDisplay();

   	ifstream File;
   	string details;

   	//extracting the client's connection details from file
   	File.open("clientConfiguration.txt");
   	if (!File) {
   		displayer->printMessageWitheNewLine("Error in opening client configuration file.");
   		exit(1);
   		}

   	getline(File,details);
   	size_t pos = details.find("IP: ");
   	string ipAddres = details.substr(pos + 4);
   	getline(File,details);
   	pos = details.find("Port: ");
   	string port = details.substr (pos + 6);
   	int portNum = atoi(port.c_str());

    Client client(ipAddres.c_str(), portNum);//creating a client and connecting it to server.
    int serverResponse = 0;
    while (serverResponse == 0) { // The client asked list of games
        int clientChoice = chooseSeverOption();
        try {
            client.connectToServer();
        } catch  (const char *msg) {
            displayer->printMessage("Failed to connect to server. Reason: ");
            displayer->printMessageWitheNewLine(msg);
            exit(-1);
        }

        // sending the command according to the client's choice
        if(clientChoice == 1)
            serverResponse = startNewGame(client);
        else if (clientChoice == 2)
            serverResponse = printListOfGames(client);
        else
            serverResponse = joinGame(client);
        if (serverResponse == 1) {	//the command request succeeded
            char chip = client.getOpeningPlayer();	//find first client to connect to server, set to be black player
            if(chip == 'X') {
                blackPlayer = new ClientPlayer(BLACK, client);
                whitePlayer = new OpponentClientPlayer(WHITE, client);
            } else if (chip == 'O') {
                whitePlayer = new ClientPlayer(WHITE, client);
                blackPlayer = new OpponentClientPlayer(BLACK, client);
            }
        }
    }
}

RemoteGame :: ~RemoteGame() {
    delete[] displayer;
    delete[] blackPlayer;
    delete[] whitePlayer;
}

int RemoteGame :: chooseSeverOption() {
		int choice = 0;
		bool invalid = true;

		displayer->printNewLine();
		displayer->printMessageWitheNewLine("Please choose your action:");
		displayer->printMessageWitheNewLine("1. Start new game.");
		displayer->printMessageWitheNewLine("2. Get list of games.");
		displayer->printMessageWitheNewLine("3. Join an ongoing game.");

		while (invalid) { //validating user's choice.
			choice = displayer->getInt();
			if (choice != 1 && choice != 2 && choice != 3) {
				displayer->printMessageWitheNewLine("Invalid input. Please enter 1, 2 or 3.");
				displayer->clearBuffer();
				displayer->ignoreInput('\n');
			} else {
				invalid = false;
			}
		}

		return choice;
}

int RemoteGame :: startNewGame(Client client) {
		string gameName;
		int serverResponse = 0;

		//getting the new game's name from the client
		displayer->printMessageWitheNewLine("Please enter your new game's name:");

    gameName = "";
    gameName = displayer->getString();

    string startCommand = "start " + gameName;
    serverResponse = client.sendCommandMessage(startCommand);
    if (serverResponse == -1)
        displayer->printMessageWitheNewLine("Name already exists. Please enter new name:");

    displayer->printMessageWitheNewLine("Waiting for opponent to join...");

		return serverResponse;
}

int RemoteGame :: printListOfGames(Client client) {
		vector<string> listOfGames;

		string listCommand = "list_games ";
		listOfGames = client.receiveStringList(listCommand);

    if(listOfGames.size() <= 0) {
        displayer->printMessageWitheNewLine("The games list is empty.");
        return 0;
        }
    displayer->printMessageWitheNewLine("The games list:");

		//printing the list
		for (int i = 0; i < (int) listOfGames.size(); i++) {
			displayer->printMessageWitheNewLine(listOfGames[i]);
		}

		displayer->printNewLine();

		return 0;
}

int RemoteGame :: joinGame(Client client) {
		string gameName;
		int serverResponse = 0;

		//getting the game's name from the client
		displayer->printMessageWitheNewLine("Which game you would like to join:");

		gameName = "";
		gameName = displayer->getString();

		string joinCommand = "join " + gameName;
		serverResponse = client.sendCommandMessage(joinCommand);

		if (serverResponse == -1) {
				displayer->printMessageWitheNewLine("This game doesn't exist. Please choose a game from the list.");
				return 0;
		} else if (serverResponse == -2) {
				displayer->printMessageWitheNewLine("The games list is empty. Please start new game.");
				displayer->printNewLine();
				return 0;
		}

		return serverResponse;
}

int RemoteGame :: playTurn(Player* p, Board* board) const {
    vector<Cell> options = board->getOptions(p->getChip());
    if (options.empty()) {
				displayer->printChar((char) p->getChip());
				displayer->printMessageWitheNewLine(": you have got no moves.");
				displayer->printMessageWitheNewLine("press enter to continue..");
				displayer->getBufferContent();

				return false;
    }//no moves can be done, turn passes to other player
    Cell chosen;

    chosen = p->doTurn(options, board->getWidth(), board->getLength());//getting cell to play
    if (chosen.getRow() == -4)
        	return 0;
    else if (chosen.getRow() == -5) { // the player closed the game
    		displayer->printMessageWitheNewLine("Game closed.");
    		displayer->printNewLine();
    		return 2;
    	}

    // putting chip on board and flipping chips accordingly
    board->putChip(p->getChip(), chosen.getRow(), chosen.getCol());
    board->cleanOptionalMovesList();

    return 1;
}

Player* RemoteGame :: getBlackPlayer() const {
	return blackPlayer;
}

Player* RemoteGame :: getWhitePlayer() const {
	return whitePlayer;
}
