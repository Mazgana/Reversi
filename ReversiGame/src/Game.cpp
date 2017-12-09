#include "Game.h"
#include "Client.h"
#include <iostream>
#include <stdlib.h>
#include "OpponentClientPlayer.h"

using namespace std;

Game::Game() {
    board = Board(default_lenth, default_width);
    blackPlayer = new HumanPlayer(BLACK);
    whitePlayer = new HumanPlayer(WHITE);
    numOfPlayers = default_num_of_players;
}

Game::Game(int players) {
    numOfPlayers = players;
    board = Board(default_lenth, default_width);
    if (numOfPlayers == 2) {
        blackPlayer = new HumanPlayer(BLACK);
        whitePlayer = new HumanPlayer(WHITE);
    } else if (numOfPlayers == 1) {
        blackPlayer = new HumanPlayer(BLACK);
        whitePlayer = new AI(WHITE);
    } else if (numOfPlayers == 3) {
        Client client("127.0.0.1", 5000);
        try {
            client.connectToServer();
        } catch  (const char *msg) {
            cout << "Failed to connect to server. Reason:" << msg << endl;
            exit(-1);
        }
        char chip = client.getOpeningPlayer();
        if(chip == 'X') {
            blackPlayer = new ClientPlayer(BLACK, client);
            whitePlayer = new OpponentClientPlayer(WHITE, client);
        } else if (chip == 'O') {
            whitePlayer = new ClientPlayer(WHITE, client);
            blackPlayer = new OpponentClientPlayer(BLACK, client);
        }
    }
}

Game:: ~Game() {
    delete[] blackPlayer;
    delete[] whitePlayer;
}

void Game :: run() {
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

bool Game :: playTurn(Player* p) {
    vector<Cell> options = board.getOptions(p->getChip());
    if (options.empty()) {
        p->skipTurn();
        return false;
    }//no moves can be done, turn passes to other player
    Cell chosen;
    if (p->isComp()) {
        int i, min, temp;
        chosen = options[0];
        min = findEnemyMaxMoves(chosen, p);

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
        chosen = p->doTurn(options);
    }
    board.putChip(p->getChip(), chosen.getRow(), chosen.getCol());// putting chip on board
    board.cleanOptionalMovesList();

    return true;
}

int Game::findEnemyMaxMoves(Cell chosen, Player *p) {
    int max = 0;
    Board currentBoard = board;
    currentBoard.putChip(p->getChip(), chosen.getCol(), chosen.getRow());
    currentBoard.flipChips(p->getChip(), chosen);

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

void Game :: endGame() const {
    cout << "GAME ENDED!" << endl;
    Status winner = board.getWinner();
    if(winner == EMPTY) {
        cout << "It's a tie!";
    }
    else {
        cout << "Player " << (char) winner << " wins!";
    }
    cout << endl;
}

int Game::maximum(int first, int second) const{
    if (first > second) {
        return first;
    } else {
        return second;
    }
}
