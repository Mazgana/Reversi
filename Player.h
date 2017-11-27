#ifndef PLAYER_H_
#define PLAYER_H_

#include "Cell.h"
#include <vector>
using namespace std;

class Player {
private:
    Status type;
public:
    virtual ~Player();
    // passes player's char representing chip.
    virtual Status getChip() const = 0;

    // passes player's opposite char representing chip.
    virtual Status getOppositeType();

    // presenting optional moves to player and getting move decision.
    virtual Cell doTurn(vector<Cell> options) = 0;
};

#endif /* PLAYER_H_ */
