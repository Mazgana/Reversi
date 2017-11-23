
#ifndef HUMENPLAYER_H_
#define HUMENPLAYER_H_

#include "Player.h"
#include "Cell.h"

class HumenPlayer {
private:
   // representing player's chip color.
    Status type;
public:
    // constructor.
    HumenPlayer();
    HumenPlayer(Status color);

    // passes player's char representing chip.
    Status getChip() const;

    // presenting optional moves to player and getting move decision.
    Cell doTurn(vector<Cell> options);
};

#endif /* HUMENPLAYER_H_ */
