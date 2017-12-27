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
   	std::string details;

   	File.open("clientConfiguration.txt");
   	if (!File) {
   		displayer->printMessageWitheNewLine("Error in opening client configuration file.");
   		exit(1);
   		}

   	std::getline(File,details);
   	std::size_t pos = details.find("IP: ");
   	std::string ipAddres = details.substr(pos + 4);
   	std::getline(File,details);
   	pos = details.find("Port: ");
   	std::string port = details.substr (pos + 6);
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

    if(clientChoice == 1)
    		startNewGame(client);
    else if (clientChoice == 2)
    		printListOfGames();
    else
    		joinGame();


    char chip = client.getOpeningPlayer();//find first client to connect to server, set to be black player
    if(chip == 'X') {
        blackPlayer = new ClientPlayer(BLACK, client);
        whitePlayer = new OpponentClientPlayer(WHITE, client);
    } else if (chip == 'O') {
        whitePlayer = new ClientPlayer(WHITE, client);
        blackPlayer = new OpponentClientPlayer(BLACK, client);
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
			cin >> choice;
			if (choice != 1 && choice != 2 && choice != 3) {
				displayer->printMessageWitheNewLine("Invalid input. Please enter 1, 2 or 3.");
				cin.get();
			} else {
				invalid = false;
			}
		}

		return choice;
}

char RemoteGame :: startNewGame(Client client) {
	std::string gameName;
	displayer->printMessageWitheNewLine("Please enter your new game's name:");
	cin >> gameName;

	std::string startCommand = "Start <" + gameName + ">";
	client.sendCommandMessage(startCommand);
}

void RemoteGame :: printListOfGames() {

}

char RemoteGame :: joinGame() {

}

bool RemoteGame :: playTurn(Player* p, Board* board) {
    vector<Cell> options = board->getOptions(p->getChip());
    if (options.empty()) {
				displayer->printChar((char) p->getChip());
				displayer->printMessageWitheNewLine(": you have got no moves.");
				displayer->printMessageWitheNewLine("press enter to continue..");
				cin.get();

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
