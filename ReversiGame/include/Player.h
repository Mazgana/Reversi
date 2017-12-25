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

    //sending message that this players turn was skipped since he has no moves.
    virtual void skipTurn() {
        cout << (char) getChip() << ": you have got no moves." << endl;
        cout << "press enter to continue.." << endl;
        cin.get();
    	}

    virtual void endGame(){};

};

#endif /* PLAYER_H_ */
