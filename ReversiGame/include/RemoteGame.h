#ifndef INCLUDE_REMOTEGAME_H_
#define INCLUDE_REMOTEGAME_H_

#include "GameLogic.h"
#include "HumanPlayer.h"
#include "ClientPlayer.h"

class RemoteGame : public GameLogic {
private:
		Board board;
		Player* blackPlayer;
		Player* whitePlayer;
		int gameType;

	//calls on functions for each turn.
	//returns true if a piece was put on board. false otherwise.
	bool playTurn(Player *p);

public:
	//constructors
	RemoteGame();
	~RemoteGame();
};

#endif /* INCLUDE_REMOTEGAME_H_ */
