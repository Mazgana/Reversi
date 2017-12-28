#ifndef INCLUDE_GAMELOGIC_H_
#define INCLUDE_GAMELOGIC_H_

#include <iostream>
#include "Board.h"
#include "Player.h"
#include "ConsoleDisplay.h"

using namespace std;

const int default_game_type = 2;
/*
 * basic game logic interface.
 */

class GameLogic {
private:
	Player* blackPlayer;
	Player* whitePlayer;

public:
	//calls on functions for each turn.
	//returns 1 if a piece was put on board. 0 if not and 2 if the game was closed.
	virtual int playTurn(Player* p, Board* board) {};

	virtual Player* getBlackPlayer() {};
	virtual Player* getWhitePlayer() {};

	virtual ~GameLogic() {};
};

#endif /* INCLUDE_GAMELOGIC_H_ */
