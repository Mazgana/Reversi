#ifndef INCLUDE_AIGAME_H_
#define INCLUDE_AIGAME_H_

#include "GameLogic.h"
#include "AI.h"
#include "HumanPlayer.h"

class AiGame : public GameLogic {
private:
		Board board;
		Player* blackPlayer;
		Player* whitePlayer;
		int gameType;

  //finds best move using given strategy (least moves for next turn).
  int findEnemyMaxMoves(Cell chosen, Player *p);

  //returns maximum number
  int maximum(int first, int second);

	//calls on functions for each turn.
	//returns true if a piece was put on board. false otherwise.
	bool playTurn(Player *p);

public:
	//constructors
	AiGame();
	~AiGame();
};

#endif /* INCLUDE_AIGAME_H_ */
