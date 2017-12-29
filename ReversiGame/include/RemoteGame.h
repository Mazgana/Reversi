#ifndef INCLUDE_REMOTEGAME_H_
#define INCLUDE_REMOTEGAME_H_

#include "GameLogic.h"
#include "ClientPlayer.h"
#include "OpponentClientPlayer.h"
#include <fstream>
#include <stdlib.h>

using namespace std;

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

	//sending the server a 'start game' command
	int startNewGame(Client client);

	//sending the server command to get the games list and print them
	int printListOfGames(Client client);

	//sending the server a command to join an ongoing game
	int joinGame(Client client);

	//calls on functions for each turn.
	//returns true if a piece was put on board. false otherwise.
	int playTurn(Player *p, Board* b) const;

	Player* getBlackPlayer() const;
	Player* getWhitePlayer() const;
};

#endif /* INCLUDE_REMOTEGAME_H_ */
