#ifndef INCLUDE_GAMEFLOW_H_
#define INCLUDE_GAMEFLOW_H_

#include "TwoHumansGame.h"
#include "AiGame.h"
#include "RemoteGame.h"
#include "ConsoleDisplay.h"

class GameFlow {
private:
		Board board;
		Display* displayer;

		int numberOfPlayers;
		GameLogic* logic;

public:
		GameFlow();
		~GameFlow();

		// printing the game's menu and creating the proper choice object
		void gameMenu();

		//running the current game - each player play it's turn until the game ends or once one
		//of the players closes the game
		void run();

		//ending the game and calculate who is the winner
		void endGame();

		//closing the game once one of the players ask it
		void closeGame();
};

#endif /* INCLUDE_GAMEFLOW_H_ */
