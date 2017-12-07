
#ifndef REVERSI_CLIENTPLAYER_H
#define REVERSI_CLIENTPLAYER_H

#include "Player.h"
#include "Cell.h"
#include "Client.h"

using namespace std;

class ClientPlayer : public Player {
private:
    Status type;
    Client contactServer;
public:
    ClientPlayer(Client client);

    ClientPlayer(Status color, Client client);

    // passes player's char representing chip.
    Status getChip() const;

    // passes player's opposite char representing chip.
    Status getOppositeType() const;

    // presenting optional moves to player and getting move decision.
    Cell doTurn(vector<Cell> options);

    bool isComp() const;
};

#endif //REVERSI_CLIENTPLAYER_H
