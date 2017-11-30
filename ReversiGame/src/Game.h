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

public:
	Game();
	Game(int);
	~Game();

	//runs basic game loop.
	void run();
	//calls on functions for each turn.
	//returns true if a piece was put on board. false otherwise.
	bool playTurn(Player* p);

	//ending game and declaring winner.
	void endGame() const;

	int findEnemyMaxMoves(Cell chosen, Player* p);

	int maximum(int first, int second);

};

#endif /* GAME_H_ */

