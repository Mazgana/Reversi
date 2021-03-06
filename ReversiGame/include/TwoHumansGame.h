#ifndef INCLUDE_TWOCLIENTSGAME_H_
#define INCLUDE_TWOCLIENTSGAME_H_

#include "GameLogic.h"
#include "HumanPlayer.h"
#include "Display.h"
#include "ConsoleDisplay.h"
#include <fstream>
#include <stdlib.h>

class TwoClientsGame : public GameLogic {
private:
	Player* blackPlayer;
	Player* whitePlayer;
	Display* displayer;

public:
	//constructors
	TwoClientsGame();
	~	TwoClientsGame();

	//calls on functions for each turn.
	//returns true if a piece was put on board. false otherwise.
	int playTurn(Player *p, Board* board) const;

	Player* getBlackPlayer() const;
	Player* getWhitePlayer() const;

};
#endif /* INCLUDE_TWOCLIENTSGAME_H_ */
