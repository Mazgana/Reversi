#include "TwoClientsGame.h"
#include "Client.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

TwoClientsGame::TwoClientsGame() {
	displayer = new ConsoleDisplay();
	blackPlayer = new HumanPlayer(BLACK);
	whitePlayer = new HumanPlayer(WHITE);
}

TwoClientsGame :: ~TwoClientsGame() {
		delete[] displayer;
    delete[] blackPlayer;
    delete[] whitePlayer;
}

bool TwoClientsGame :: playTurn(Player* p, Board* board) {
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

    board->putChip(p->getChip(), chosen.getRow(), chosen.getCol());// putting chip on board and flipping chips accordingly
    board->cleanOptionalMovesList();

    return true;
}

Player* TwoClientsGame :: getBlackPlayer() {
	return blackPlayer;
}

Player* TwoClientsGame :: getWhitePlayer() {
	return whitePlayer;
}
