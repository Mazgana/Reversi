#include "RemoteGame.h"
#include "Client.h"
#include "OpponentClientPlayer.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

RemoteGame::RemoteGame() {
		displayer = new ConsoleDisplay();

   	ifstream File;
   	string details;

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
    try {
        client.connectToServer();
    } catch  (const char *msg) {
    	  displayer->printMessage("Failed to connect to server. Reason: ");
    	  displayer->printMessageWitheNewLine(msg);
        exit(-1);
      	}

    int clientChoice = chooseSeverOption();
    int serverResponse = 0;

    if(clientChoice == 1)
    	serverResponse = startNewGame(client);
    else if (clientChoice == 2)
    		printListOfGames(client);
    else
    		joinGame(client);

    cout << serverResponse << endl;

		if (serverResponse == 1) {
			char chip = client.getOpeningPlayer();//find first client to connect to server, set to be black player
			if(chip == 'X') {
				blackPlayer = new ClientPlayer(BLACK, client);
				whitePlayer = new OpponentClientPlayer(WHITE, client);
			} else if (chip == 'O') {
				whitePlayer = new ClientPlayer(WHITE, client);
				blackPlayer = new OpponentClientPlayer(BLACK, client);
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
		displayer->printMessageWitheNewLine("3. Join to an on going game.");

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

		displayer->printMessageWitheNewLine("Please enter your new game's name:");
		gameName = displayer->getString();

		string startCommand = "start " + gameName;
		serverResponse = client.sendCommandMessage(startCommand);

		return serverResponse;
}

void RemoteGame :: printListOfGames(Client client) {
		vector<string> listOfGames;

		string listCommand = "list_games ";
		listOfGames = client.reciveStringList(listCommand);

		for (int i = 0; i < (int) listOfGames.size(); i++) {
			cout << "client: ";
			displayer->printMessageWitheNewLine(listOfGames[i]);
		}
}

int RemoteGame :: joinGame(Client client) {
		string gameName;
		int serverResponse = 0;

		displayer->printMessageWitheNewLine("Which game you would like to join:");
		gameName = displayer->getString();

		string joinCommand = "join " + gameName;
		serverResponse = client.sendCommandMessage(joinCommand);

		return serverResponse;

}

bool RemoteGame :: playTurn(Player* p, Board* board) {
    vector<Cell> options = board->getOptions(p->getChip());
    if (options.empty()) {
				displayer->printChar((char) p->getChip());
				displayer->printMessageWitheNewLine(": you have got no moves.");
				displayer->printMessageWitheNewLine("press enter to continue..");
				displayer->getBufferContent();

				return false;
    }//no moves can be done, turn passes to other player
    Cell chosen;

    chosen = p->doTurn(options);//getting cell to play
    if (chosen.getRow() == -4)
        	return false;

    board->putChip(p->getChip(), chosen.getRow(), chosen.getCol());// putting chip on board and flipping chips accordingly
    board->cleanOptionalMovesList();

    return true;
}

Player* RemoteGame :: getBlackPlayer() {
	return blackPlayer;
}

Player* RemoteGame :: getWhitePlayer() {
	return whitePlayer;
}
