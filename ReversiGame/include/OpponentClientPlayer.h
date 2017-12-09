
#ifndef REVERSI_OPPONENTCLIENTPLAYER_H
#define REVERSI_OPPONENTCLIENTPLAYER_H

#include "Player.h"
#include "Cell.h"
#include "Client.h"

using namespace std;
/*
 * player of game with two clients. this player is the opponent playing on another computer.
 */
class OpponentClientPlayer : public Player {
private:
    Status type;
    Client messageReceiver;
public:
    //constructors
    OpponentClientPlayer(Client client);
    OpponentClientPlayer(Status color, Client client);

    // passes player's char representing chip.
    Status getChip() const;

    // passes player's opposite char representing chip.
    Status getOppositeType() const;

    // presenting optional moves to player and getting move decision.
    Cell doTurn(vector<Cell> options);

    //checkimg if player is a computer
    bool isComp() const;

    //sending message that turn was skipped
    void skipTurn();
};

#endif //REVERSI_OPPONENTCLIENTPLAYER_H
