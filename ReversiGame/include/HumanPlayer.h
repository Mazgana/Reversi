#ifndef REVERSI_HUMANPLAYER_H
#define REVERSI_HUMANPLAYER_H

#include "Player.h"
#include "ConsoleDisplay.h"
#include <limits>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

/*
 * human player, playing on current computer, using console
 */
class HumanPlayer : public Player{
private:
    // representing player's chip color.
    Status type;
		Display* displayer;

public:
    // constructor.
    HumanPlayer();
    HumanPlayer(Status color);
    ~HumanPlayer();

    // passes player's char representing chip.
    Status getChip() const;

    Status getOppositeType() const;

    // presenting optional moves to player and getting move decision.
    Cell doTurn(vector<Cell> options);

    //Is the player a computer - return false
    bool isComp() const;
};

#endif //REVERSI_HUMANPLAYER_H
