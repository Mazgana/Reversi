#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include "HumanPlayer.h"

class Game {
private:
  Board board;
	HumanPlayer blackPlayer;
	HumanPlayer whitePlayer;

public:
	Game();

	//Starting new game with default settings of one board and two players.
	void startNewGame();

	//runs basic game loop.
  void run();
  //calls on functions for each turn.
  //returns true if a piece was put on board. false otherwise.
  bool playTurn(HumanPlayer p);

  bool playTurn(AI p);
  //ending game and declaring winner.
  void endGame() const;

  int findEnemyMaxMoves(Cell chosen, Player currentPlayer);

};

#endif /* GAME_H_ */
