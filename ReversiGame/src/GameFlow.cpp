#include "GameFlow.h"
#include "TwoClientsGame.h"
#include "AiGame.h"
#include "RemoteGame.h"
#include "ConsoleDisplay.h"

GameFlow :: GameFlow() {
	displayer = new ConsoleDisplay();

	int gameType = 0;
	bool invalid = true;

	//opening message for reversi game.
	displayer->printMessageWitheNewLine("Welcome to Reversi!");
	displayer->printMessageWitheNewLine("Choose an opponent type:");
	displayer->printMessageWitheNewLine("1. a human local player");
	displayer->printMessageWitheNewLine("2. an AI player");
	displayer->printMessageWitheNewLine("3. a remote player");

	while (invalid) {//validating users game choice.
		cin >> gameType;
		if (gameType != 1 && gameType != 2 && gameType != 3) {
			displayer->printMessageWitheNewLine("Invalid input. Please enter 1, 2 or 3.");
		} else {
			invalid = false;
		}
	}

	numberOfPlayers = gameType;
  board = Board(default_lenth, default_width);

	if (numberOfPlayers == 1) {
		logic = new TwoClientsGame();
	} else if (numberOfPlayers == 2) {
		logic = new AiGame();
	} else {
		logic = new RemoteGame();
	}
}

GameFlow :: ~GameFlow() {
	delete[] displayer;
}

//runs basic game loop.
void GameFlow :: run() {    //initializing board and starting.
    bool oPlayed = true, xPlayed;
    board.initialize();
    displayer->printBoard(board);

    //playing game, 1 round per player.
    while (!board.isBoardFull()) {
        xPlayed = logic->playTurn(logic->getBlackPlayer(), &board);
        if (!xPlayed && !oPlayed) {
            //when no more moves can be done.
            break;
        }
    displayer->printBoard(board);
    oPlayed = logic->playTurn(logic->getWhitePlayer(), &board);
    if (!xPlayed && !oPlayed) {
        //when no more moves can be done.
        break;
        }
    displayer->printBoard(board);
    }
    endGame();
}

//ending game and declaring winner.
void GameFlow :: endGame() {
	    //ending game and announcing winner
		  displayer->printMessageWitheNewLine("GAME ENDED!");
	    Status winner = board.getWinner();
	    if(winner == EMPTY) {
	    	displayer->printMessage("It's a tie!");
	    	}
	    else {
	    	displayer->printMessage("Player ");
	    	displayer->printChar((char) winner);
	    	displayer->printMessageWitheNewLine(" wins!");
	    	}

	    logic->getBlackPlayer()->endGame();
	    logic->getWhitePlayer()->endGame();
}
