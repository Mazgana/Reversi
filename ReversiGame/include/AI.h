#ifndef REVERSI_AI_H
#define REVERSI_AI_H

#include "Player.h"
#include <limits>
#include <iostream>

/*
 * AI player class. plays game specified game logic and printing it to console.
 */
class AI : public Player{
private:
    // representing player's chip color.
    Status type;
public:
    // constructors.
    AI();
    AI(Status color);

    // passes player's char representing chip.
    Status getChip() const;

    Status getOppositeType() const;

    // presenting optional moves to player and getting move decision.
    Cell doTurn(vector<Cell> options);

    //Is the player a computer - return true
    bool isComp() const;
};

#endif //REVERSI_AI_H
