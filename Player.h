#ifndef PLAYER_H_
#define PLAYER_H_

#include "Cell.h"
#include <vector>
using namespace std;

class Player {
private:
    Status type;
public:
    Player();
    virtual ~Player();
    // passes player's char representing chip.
    virtual Status getType() const;
    // presenting optional moves to player and getting move decision.
    virtual Cell doTurn(vector<Cell> options);
};

#endif /* PLAYER_H_ */
