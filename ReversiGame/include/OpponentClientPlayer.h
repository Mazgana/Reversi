
#ifndef REVERSI_OPPONENTCLIENTPLAYER_H
#define REVERSI_OPPONENTCLIENTPLAYER_H

#include "Player.h"
#include "Cell.h"
#include "Client.h"

using namespace std;

class OpponentClientPlayer : public Player {
private:
    Status type;
    Client messageReceiver;
public:
    OpponentClientPlayer(Client client);

    OpponentClientPlayer(Status color, Client client);

    // passes player's char representing chip.
    Status getChip() const;

    // passes player's opposite char representing chip.
    Status getOppositeType() const;

    // presenting optional moves to player and getting move decision.
    Cell doTurn(vector<Cell> options);

    bool isComp() const;

    void skipTurn();
};

#endif //REVERSI_OPPONENTCLIENTPLAYER_H
