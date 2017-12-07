
#ifndef REVERSI_COMPONENTCLIENTPLAYER_H
#define REVERSI_COMPONENTCLIENTPLAYER_H

#include "Player.h"
#include "Cell.h"
#include "Client.h"

using namespace std;

class ComponentClientPlayer : public Player {
private:
    Status type;
    Client messageReceiver;
public:
    ComponentClientPlayer(Client client);

    ComponentClientPlayer(Status color, Client client);

    // passes player's char representing chip.
    Status getChip() const;

    // passes player's opposite char representing chip.
    Status getOppositeType() const;

    // presenting optional moves to player and getting move decision.
    Cell doTurn(vector<Cell> options);

    bool isComp() const;
};

#endif //REVERSI_COMPONENTCLIENTPLAYER_H
