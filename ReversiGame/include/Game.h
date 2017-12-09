#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include "HumanPlayer.h"
#include "AI.h"
#include "ClientPlayer.h"
#include "OpponentClientPlayer.h"

const int default_game_type = 2;
/*
 * game class. runs game and game logic, moving from one player to other until game ends.
 */
class Game {
private:
	Board board;
	Player* blackPlayer;
	Player* whitePlayer;
	int gameType;

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
	//constructors.
	Game();
	Game(int);
	~Game();

	//runs basic game loop.
	void run();
};

#endif /* GAME_H_ */
