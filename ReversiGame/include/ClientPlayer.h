
#ifndef REVERSI_CLIENTPLAYER_H
#define REVERSI_CLIENTPLAYER_H

#include "Player.h"
#include "Cell.h"
#include "Client.h"

using namespace std;
/*
 * Client player class. current player connecting to server to play against another remote player.
 */
class ClientPlayer : public Player {
private:
    Status type;
    Client contactServer;
public:
    //constructors
    ClientPlayer(Client client);
    ClientPlayer(Status color, Client client);

    // passes player's char representing chip.
    Status getChip() const;

    // passes player's opposite char representing chip.
    Status getOppositeType() const;

    // presenting optional moves to player and getting move decision.
    Cell doTurn(vector<Cell> options);

    //checking if this player is a computer
    bool isComp() const;

    //send message that turn was skipped
    void skipTurn();

    void endGame();
};

#endif //REVERSI_CLIENTPLAYER_H
