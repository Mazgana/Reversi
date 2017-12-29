#include "TwoHumansGame.h"

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

int TwoClientsGame :: playTurn(Player* p, Board* board) const {
    vector<Cell> options = board->getOptions(p->getChip());
    if (options.empty()) {
				displayer->printChar((char) p->getChip());
				displayer->printMessageWitheNewLine(": you have got no moves.");
				displayer->printMessageWitheNewLine("press enter to continue..");
				displayer->getBufferContent();

        return 0;
    }//no moves can be done, turn passes to other player
    Cell chosen;
    chosen = p->doTurn(options);//getting cell to play

    board->putChip(p->getChip(), chosen.getRow(), chosen.getCol());// putting chip on board and flipping chips accordingly
    board->cleanOptionalMovesList();

    return 1;
}

Player* TwoClientsGame :: getBlackPlayer() const {
	return blackPlayer;
}

Player* TwoClientsGame :: getWhitePlayer() const {
	return whitePlayer;
}
