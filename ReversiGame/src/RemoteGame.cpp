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
    gameType = 3;
    board = Board(default_lenth, default_width);

   	ifstream File;
   	std::string details;

   	File.open("clientConfiguration.txt");
   	if (!File) {
   		cout << "Error in opening client configuration file." << endl;
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
        cout << "Failed to connect to server. Reason:" << msg << endl;
        exit(-1);
      	}
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
    delete[] blackPlayer;
    delete[] whitePlayer;
}

void RemoteGame :: run() {
    //initializing board and starting.
    bool oPlayed = true, xPlayed;
    board.initialize();
    board.print();

    //playing game, 1 round per player.
    while (!board.isBoardFull()) {
        xPlayed = playTurn(blackPlayer);
        if (!xPlayed && !oPlayed) {
            //when no more moves can be done.
            break;
        }
        board.print();
        oPlayed = playTurn(whitePlayer);
        if (!xPlayed && !oPlayed) {
            //when no more moves can be done.
            break;
        }
        board.print();
    }
    endGame();
}

bool RemoteGame :: playTurn(Player* p) {
    vector<Cell> options = board.getOptions(p->getChip());
    if (options.empty()) {
        p->skipTurn();
        return false;
    }//no moves can be done, turn passes to other player
    Cell chosen;
    if (p->isComp()) {//get board to play computer strategy.
        int i, min, temp;
        chosen = options[0];
        min = findEnemyMaxMoves(chosen, p);//finding maximum moves and choosing the minimum of those.

        for (i = 1; i < (int)options.size(); i++) {
            temp = findEnemyMaxMoves(options[i], p);
            if (temp < min) {
                min = temp;
                chosen = options[i];
            }
        }
        cout << (char) p->getChip() << " played ";
        chosen.printCell();
        cout << endl << endl;
    } else {
        chosen = p->doTurn(options);//getting cell to play
        if (chosen.getRow() == -4)
        	return false;
    	}
    board.putChip(p->getChip(), chosen.getRow(), chosen.getCol());// putting chip on board and flipping chips accordingly
    board.cleanOptionalMovesList();

    return true;
}

int RemoteGame::findEnemyMaxMoves(Cell chosen, Player *p) const {
    int max = 0;
    Board currentBoard = board;//creating board copy to try strategy
    currentBoard.putChip(p->getChip(), chosen.getCol(), chosen.getRow());
    currentBoard.flipChips(p->getChip(), chosen);
    //checking for maximum opponent moves.
    max = maximum(currentBoard.doOneWay(p->getOppositeType(), chosen.getRow(), -1, chosen.getCol(), 0, true), max);
    max = maximum(currentBoard.doOneWay(p->getOppositeType(), chosen.getRow(), 1, chosen.getCol(), 0, true), max);
    max = maximum(currentBoard.doOneWay(p->getOppositeType(), chosen.getRow(), -1, chosen.getCol(), 1, true), max);
    max = maximum(currentBoard.doOneWay(p->getOppositeType(), chosen.getRow(), 1, chosen.getCol(), 1, true), max);
    max = maximum(currentBoard.doOneWay(p->getOppositeType(), chosen.getRow(), 0, chosen.getCol(), 1, true), max);
    max = maximum(currentBoard.doOneWay(p->getOppositeType(), chosen.getRow(), -1, chosen.getCol(), -1, true), max);
    max = maximum(currentBoard.doOneWay(p->getOppositeType(), chosen.getRow(), 1, chosen.getCol(), -1, true), max);
    max = maximum(currentBoard.doOneWay(p->getOppositeType(), chosen.getRow(), 0, chosen.getCol(), -1, true), max);

    return max;
}

void RemoteGame :: endGame() {
    //ending game and announcing winner
    cout << "GAME ENDED!" << endl;
    Status winner = board.getWinner();
    if(winner == EMPTY) {
        cout << "It's a tie!";
    	}
    else {
        cout << "Player " << (char) winner << " wins!";
    	}
    cout << endl;

  	blackPlayer->endGame();
    whitePlayer->endGame();
}

int RemoteGame::maximum(int first, int second) const {
    if (first > second) {
        return first;
    } else {
        return second;
    }
}
