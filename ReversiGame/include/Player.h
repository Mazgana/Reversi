#ifndef PLAYER_H_
#define PLAYER_H_

#include "Cell.h"
#include <vector>
#include <iostream>

using namespace std;
/*
 * basic player interface.
 */
class Player {
private:
    Status type;

public:
    // passes player's char representing chip.
    virtual Status getChip() const = 0;

    // passes player's opposite char representing chip.
    virtual Status getOppositeType() const = 0;

    // presenting optional moves to player and getting move decision.
    virtual Cell doTurn(vector<Cell> options) = 0;

    //checking if this player is a computer.
    virtual bool isComp() const = 0;

    virtual void endGame(){};
};

#endif /* PLAYER_H_ */
