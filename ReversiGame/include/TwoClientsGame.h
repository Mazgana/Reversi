#ifndef INCLUDE_TWOCLIENTSGAME_H_
#define INCLUDE_TWOCLIENTSGAME_H_

#include "GameLogic.h"
#include "HumanPlayer.h"

class TwoClientsGame : public GameLogic {
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
	TwoClientsGame();
	~TwoClientsGame();

};
#endif /* INCLUDE_TWOCLIENTSGAME_H_ */
