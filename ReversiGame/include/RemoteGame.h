#ifndef INCLUDE_REMOTEGAME_H_
#define INCLUDE_REMOTEGAME_H_

#include "GameLogic.h"
#include "HumanPlayer.h"
#include "ClientPlayer.h"

class RemoteGame : public GameLogic {
private:
	Player* blackPlayer;
	Player* whitePlayer;
	Display* displayer;

public:
	//constructors
	RemoteGame();
	~RemoteGame();

	// The client choose his action - start new game, get list of games or join to an on going game.
	int chooseSeverOption();

	int startNewGame(Client client);

	int printListOfGames(Client client);

	int joinGame(Client client);

	//calls on functions for each turn.
	//returns true if a piece was put on board. false otherwise.
	int playTurn(Player *p, Board* b);

	Player* getBlackPlayer();
	Player* getWhitePlayer();
};

#endif /* INCLUDE_REMOTEGAME_H_ */
