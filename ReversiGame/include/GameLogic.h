#ifndef INCLUDE_GAMELOGIC_H_
#define INCLUDE_GAMELOGIC_H_

#include <iostream>
#include "Board.h"
#include "Player.h"
#include "ConsoleDisplay.h"

const int default_game_type = 2;
/*
 * basic game logic interface.
 */

class GameLogic {
private:
	Player* blackPlayer;
	Player* whitePlayer;

public:
	virtual ~GameLogic() {}

	//calls on functions for each turn.
	//returns 1 if a piece was put on board. 0 if not and 2 if the game was closed.
	virtual int playTurn(Player* p, Board* board) const = 0;

	//getting the game's payers
	virtual Player* getBlackPlayer() const = 0;
	virtual Player* getWhitePlayer() const = 0;
};

#endif /* INCLUDE_GAMELOGIC_H_ */
