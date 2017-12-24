#ifndef INCLUDE_GAMELOGIC_H_
#define INCLUDE_GAMELOGIC_H_

#include <iostream>
#include "Board.h"
#include "Player.h"

using namespace std;

const int default_game_type = 2;
/*
 * basic game logic interface.
 */

class GameLogic {
private:
	Board board;
	Player* blackPlayer;
	Player* whitePlayer;
	int gameType;

  //finds best move using given strategy (least moves for next turn).
  virtual int findEnemyMaxMoves(Cell chosen, Player* p) const = 0;

  //returns maximum number
  virtual int maximum(int first, int second) const = 0;

  //ending game and declaring winner.
  virtual void endGame() {};

	//calls on functions for each turn.
	//returns true if a piece was put on board. false otherwise.
	virtual bool playTurn(Player* p) {};

public:
	//runs basic game loop.
	virtual void run() {
	    //initializing board and starting.
	    bool oPlayed = true, xPlayed;
	    board.initialize();
	    board.print();

	    //playing game, 1 round per player.
	    while (!board.isBoardFull()) {
	        xPlayed = playTurn(blackPlayer);
	        if (!xPlayed && !oPlayed) {
	            //when no more moves can be done.
	            break;
	        }
	        board.print();
	        oPlayed = playTurn(whitePlayer);
	        if (!xPlayed && !oPlayed) {
	            //when no more moves can be done.
	            break;
	        }
	        board.print();
	    }
	    endGame();
	};

	virtual ~GameLogic() {};
};

#endif /* INCLUDE_GAMELOGIC_H_ */
