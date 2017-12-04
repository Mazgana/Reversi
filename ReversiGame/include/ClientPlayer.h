
#ifndef REVERSI_CLIENTPLAYER_H
#define REVERSI_CLIENTPLAYER_H

#include "Player.h"
#include "Cell.h"

using namespace std;

class ClientPlayer : public Player {
private:
    Status type;
public:
    ClientPlayer();

    ClientPlayer(Status color);

    // passes player's char representing chip.
    virtual Status getChip() const = 0;

    // passes player's opposite char representing chip.
    virtual Status getOppositeType() const = 0;

    // presenting optional moves to player and getting move decision.
    virtual Cell doTurn(vector<Cell> options) = 0;

    virtual bool isComp() const = 0;
};

#endif //REVERSI_CLIENTPLAYER_H
