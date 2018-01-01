#include "GameFlow.h"

GameFlow :: GameFlow() {
	displayer = new ConsoleDisplay();

	gameMenu();
}

GameFlow :: ~GameFlow() {
}

void GameFlow :: gameMenu() {
	int gameType = 0;
	bool invalid = true;

	//opening message for reversi game.
	displayer->printMessageWitheNewLine("Welcome to Reversi!");
	displayer->printMessageWitheNewLine("Choose an opponent type:");
	displayer->printMessageWitheNewLine("1. a human local player");
	displayer->printMessageWitheNewLine("2. an AI player");
	displayer->printMessageWitheNewLine("3. a remote player");

	while (invalid) {		//validating users game choice.
		gameType = displayer->getInt();
		if (gameType != 1 && gameType != 2 && gameType != 3) {
			displayer->printMessageWitheNewLine("Invalid input! Please enter 1, 2 or 3.");
			displayer->clearBuffer();
			displayer->ignoreInput('\n');
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

//runs basic game loop.
void GameFlow :: run() {
	//initializing board and starting.
    int oPlayed = 1, xPlayed;
    bool closed = false;
    board.initialize();
    displayer->printBoard(board);

    //playing game, 1 round per player.
    while (!board.isBoardFull()) {
        xPlayed = logic->playTurn(logic->getBlackPlayer(), &board);
        if (xPlayed == 0 && oPlayed == 0) {
            //when no more moves can be done.
            break;
        } else if (xPlayed == 2) {
        	//X closed the game
        	closed = true;
        	break;
        		}

        displayer->printBoard(board);

        oPlayed = logic->playTurn(logic->getWhitePlayer(), &board);
        if (xPlayed == 0 && oPlayed == 0) {
        	//when no more moves can be done.
        	break;
        } else if (oPlayed == 2) {
        	//O closed the game
        	closed = true;
        	break;
        		}

        displayer->printBoard(board);
    	}

		if (closed) {
			endGame(2); // One of the players closed the game
		} else {
			endGame(1); // The game ended
		}
}

//ending game and declaring winner.
void GameFlow :: endGame(int cause) {
	    //ending game and announcing winner
			if (cause == 1) {
				  displayer->printMessageWitheNewLine("GAME ENDED!");
			}

	    Status winner = board.getWinner();
	    if(winner == EMPTY) {
	    	displayer->printMessageWitheNewLine("It's a tie!");
	    	}
	    else {
	    	displayer->printMessage("Player ");
	    	displayer->printChar((char) winner);
	    	displayer->printMessageWitheNewLine(" wins!");
	    	}

	    logic->getBlackPlayer()->endGame();
	    logic->getWhitePlayer()->endGame();

		gameMenu();
		run();
}
