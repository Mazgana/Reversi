#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include "HumanPlayer.h"
#include "AI.h"

const int default_num_of_players = 2;

class Game {
private:
  Board board;
	HumanPlayer blackPlayer;
	HumanPlayer whitePlayer;
	AI whiteAiPlayer;

	int numOfPlayers;

public:
	Game();
	Game(int);

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

  int findEnemyMaxMoves(Cell chosen, AI currentPlayer);

  int maximum(int first, int second);

};

#endif /* GAME_H_ */
