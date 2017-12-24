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

bool TwoClientsGame :: playTurn(Player* p) {
    vector<Cell> options = board.getOptions(p->getChip());
    if (options.empty()) {
        p->skipTurn();
        return false;
    }//no moves can be done, turn passes to other player
    Cell chosen;
    chosen = p->doTurn(options);//getting cell to play

    board.putChip(p->getChip(), chosen.getRow(), chosen.getCol());// putting chip on board and flipping chips accordingly
    board.cleanOptionalMovesList();

    return true;
}
