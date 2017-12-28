#ifndef INCLUDE_AIGAME_H_
#define INCLUDE_AIGAME_H_

#include "GameLogic.h"
#include "AI.h"
#include "HumanPlayer.h"

class AiGame : public GameLogic {
private:
	Player* blackPlayer;
	Player* whitePlayer;
	Display* displayer;

  //finds best move using given strategy (least moves for next turn).
  int findEnemyMaxMoves(Cell chosen, Player *p, Board* b);

  //returns maximum number
  int maximum(int first, int second);

public:
	//constructors
	AiGame();
	~AiGame();

	//calls on functions for each turn.
	//returns true if a piece was put on board. false otherwise.
	int playTurn(Player *p, Board* b);

	Player* getBlackPlayer();
	Player* getWhitePlayer();
};

#endif /* INCLUDE_AIGAME_H_ */
