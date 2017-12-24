#include "TwoClientsGame.h"
#include "Client.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

TwoClientsGame::TwoClientsGame() {
    board = Board(default_lenth, default_width);
    blackPlayer = new HumanPlayer(BLACK);
    whitePlayer = new HumanPlayer(WHITE);
    gameType = 1;
}

TwoClientsGame :: ~TwoClientsGame() {
    delete[] blackPlayer;
    delete[] whitePlayer;
}

void TwoClientsGame :: run() {
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

bool TwoClientsGame :: playTurn(Player* p) {
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

int TwoClientsGame::findEnemyMaxMoves(Cell chosen, Player *p) const {
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

void TwoClientsGame :: endGame() {
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

int TwoClientsGame::maximum(int first, int second) const {
    if (first > second) {
        return first;
    } else {
        return second;
    }
}
