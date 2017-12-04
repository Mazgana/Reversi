#ifndef REVERSI_HUMANPLAYER_H
#define REVERSI_HUMANPLAYER_H

#include "Player.h"
#include "Cell.h"

class HumanPlayer : public Player{
private:
    // representing player's chip color.
    Status type;
public:
    // constructor.
    HumanPlayer();

    HumanPlayer(Status color);

    // passes player's char representing chip.
    Status getChip() const;

    Status getOppositeType() const;

    // presenting optional moves to player and getting move decision.
    Cell doTurn(vector<Cell> options);

    //Is the player a computer - return false
    bool isComp() const;
};

#endif //REVERSI_HUMANPLAYER_H
