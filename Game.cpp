#include "Game.h"

#include <iostream>
using namespace std;

Game::Game() {
  board = Board(8, 8);
	blackPlayer = HumanPlayer(BLACK);
	whitePlayer = HumanPlayer(WHITE);
}

void Game :: run() {
    //initializing board and starting.
    bool play = true;
    bool oPlayed = true, xPlayed = true;
    board.initialize();
    //playing game, 1 round per player.
    while (play) {
        board.print();
        oPlayed = playTurn(blackPlayer);
        if (!xPlayed && !oPlayed) {
            //when no more moves can be done.
            endGame();
            break;
        }
        board.print();
        xPlayed = playTurn(whitePlayer);
        if (!xPlayed && !oPlayed) {
            //when no more moves can be done.
            endGame();
            break;
        }
    }
}

bool Game :: playTurn(HumanPlayer p) {
    vector<Cell> options = board.getOptions(p.getChip());
    if (options.empty()) {
        cin.get();
        cout << (char)p.getChip() << ": Youv'e got no moves." << endl;
        cout << "press enter to continue.." << endl;
        cin.get();
        return false;
    }//no moves can be done, turn passes to other player
    Cell chosen = p.doTurn(options);
    board.putChip(p.getChip(), chosen.getCol(), chosen.getRow());// putting chip on board
    board.flipChips(p.getChip(), chosen);
    return true;
}

void Game :: endGame() const {
    cout << "GAME ENDED!" << endl;
    char chip = board.getWinner();
    if(chip == ' ') {
        cout << "It's a tie!";
    }
    else {
        cout << "Player " << chip << " wins!";
    }
    cout << endl;
}
