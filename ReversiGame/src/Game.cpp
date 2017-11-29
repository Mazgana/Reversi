#include "Game.h"

#include <iostream>
using namespace std;

Game::Game() {
    board = Board(default_lenth, default_width);
	blackPlayer = HumanPlayer(BLACK);
	whitePlayer = HumanPlayer(WHITE);
	numOfPlayers = default_num_of_players;
}

Game::Game(int players) {
	numOfPlayers = players;
    board = Board(default_lenth, default_width);
    if (numOfPlayers == 2) {
	 	blackPlayer = HumanPlayer(BLACK);
		whitePlayer = HumanPlayer(WHITE);
    } else if (numOfPlayers == 1) {
        whiteAiPlayer = AI(WHITE);
		blackPlayer = HumanPlayer(BLACK);
    }
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
            endGame();
            break;
        }
        board.print();
        if (numOfPlayers == 2)
        	oPlayed = playTurn(whitePlayer);
        else if (numOfPlayers == 1)
        	oPlayed = playTurn(whiteAiPlayer);

        if (!xPlayed && !oPlayed) {
            //when no more moves can be done.
            endGame();
            break;
        		}
        board.print();
    	}
    endGame();
}

bool Game :: playTurn(HumanPlayer p) {
    vector<Cell> options = board.getOptions(p.getChip());
    if (options.empty()) {
        cout << (char)p.getChip() << ": Youv'e got no moves." << endl;
        cout << "press enter to continue.." << endl;
        cin.get();
        return false;
    }//no moves can be done, turn passes to other player
    Cell chosen = p.doTurn(options);
    board.putChip(p.getChip(), chosen.getRow(), chosen.getCol());// putting chip on board
    board.flipChips(p.getChip(), chosen);
    board.cleanOptionalMovesList();

    return true;
}

bool Game :: playTurn(AI p) {
	int i, min, temp;
	Cell minCell;

	vector<Cell> options = board.getOptions(p.getChip());
	minCell = options[0];
	min = findEnemyMaxMoves(minCell, p);

	for (i = 1; i < (int)options.size(); i++) {
		temp = findEnemyMaxMoves(options[i], p);
		if (temp < min) {
			min = temp;
			minCell = options[i];
		}
	}

   board.putChip(p.getChip(), minCell.getRow(), minCell.getCol());// putting chip on board
   board.flipChips(p.getChip(), minCell);
   board.cleanOptionalMovesList();

   cout << (char) p.getChip() << " played ";
   minCell.printCell();
   cout << endl << endl;

   return true;
}

int Game::findEnemyMaxMoves(Cell chosen, AI currentPlayer) {
	 int max = 0;
	 Board currentBoard = board;
	 currentBoard.putChip(currentPlayer.getChip(), chosen.getCol(), chosen.getRow());
	 currentBoard.flipChips(currentPlayer.getChip(), chosen);

	 max = maximum(currentBoard.doOneWay(currentPlayer.getOppositeType(), chosen.getRow(), -1, chosen.getCol(), 0, true), max);
	 max = maximum(currentBoard.doOneWay(currentPlayer.getOppositeType(), chosen.getRow(), 1, chosen.getCol(), 0, true), max);
	 max = maximum(currentBoard.doOneWay(currentPlayer.getOppositeType(), chosen.getRow(), -1, chosen.getCol(), 1, true), max);
	 max = maximum(currentBoard.doOneWay(currentPlayer.getOppositeType(), chosen.getRow(), 1, chosen.getCol(), 1, true), max);
	 max = maximum(currentBoard.doOneWay(currentPlayer.getOppositeType(), chosen.getRow(), 0, chosen.getCol(), 1, true), max);
	 max = maximum(currentBoard.doOneWay(currentPlayer.getOppositeType(), chosen.getRow(), -1, chosen.getCol(), -1, true), max);
	 max = maximum(currentBoard.doOneWay(currentPlayer.getOppositeType(), chosen.getRow(), 1, chosen.getCol(), -1, true), max);
	 max = maximum(currentBoard.doOneWay(currentPlayer.getOppositeType(), chosen.getRow(), 0, chosen.getCol(), -1, true), max);

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

int Game::maximum(int first, int second) {
	if (first > second) {
		return first;
	} else {
		return second;
	}
}