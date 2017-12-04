#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include "HumanPlayer.h"
#include "AI.h"

const int default_num_of_players = 2;

class Game {
private:
	Board board;
	Player* blackPlayer;
	Player* whitePlayer;
	int numOfPlayers;

  //finds best move using given strategy (least moves for next turn).
  int findEnemyMaxMoves(Cell chosen, Player* p);

  //returns maximum number
  int maximum(int first, int second) const;

  //ending game and declaring winner.
  void endGame() const;

	//calls on functions for each turn.
	//returns true if a piece was put on board. false otherwise.
	bool playTurn(Player* p);

public:
	Game();
	Game(int);
	~Game();

	//runs basic game loop.
	void run();
};

#endif /* GAME_H_ */
