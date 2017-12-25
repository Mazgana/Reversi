#ifndef INCLUDE_GAMEFLOW_H_
#define INCLUDE_GAMEFLOW_H_

#include "GameLogic.h"
#include "Display.h"

class GameFlow {
private:
		Board board;
		Display* displayer;

		int numberOfPlayers;
		GameLogic* logic;

public:
		GameFlow();
		~GameFlow();

		void run();
		void skipTurn();
		void endGame();
};

#endif /* INCLUDE_GAMEFLOW_H_ */
