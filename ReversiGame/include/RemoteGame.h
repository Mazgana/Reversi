#ifndef INCLUDE_REMOTEGAME_H_
#define INCLUDE_REMOTEGAME_H_

#include "GameLogic.h"
#include "HumanPlayer.h"
#include "ClientPlayer.h"

class RemoteGame : public GameLogic {
private:
	Player* blackPlayer;
	Player* whitePlayer;
	Display* displayer;

public:
	//constructors
	RemoteGame();
	~RemoteGame();

	//calls on functions for each turn.
	//returns true if a piece was put on board. false otherwise.
	bool playTurn(Player *p, Board* b);

	Player* getBlackPlayer();
	Player* getWhitePlayer();
};

#endif /* INCLUDE_REMOTEGAME_H_ */
