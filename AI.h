#ifndef REVERSI_AI_H
#define REVERSI_AI_H

#include "Player.h"
#include "Cell.h"

class AI : public Player{
private:
    // representing player's chip color.
    Status type;
public:
    // constructor.
    AI();

    AI(Status color);

    ~AI();

    // passes player's char representing chip.
    Status getChip() const;

    Status getOppositeType();

    // presenting optional moves to player and getting move decision.
    Cell doTurn(vector<Cell> options) override;
};

#endif //REVERSI_AI_H
