#include <iostream>
#include "componentClientPlayer.h"

using namespace std;

ComponentClientPlayer::ComponentClientPlayer(Client client) : messageReceiver(client) {
    type = WHITE;
}

ComponentClientPlayer::ComponentClientPlayer(Status t, Client client) : type(t), messageReceiver(client) {
}

Cell ComponentClientPlayer :: doTurn(vector<Cell> options) {
    int x,y;
    x = messageReceiver.receiveCoordinate();
    y = messageReceiver.receiveCoordinate();
    Cell c(x,y);
    return c;
}

Status ComponentClientPlayer :: getChip() const{
    return type;
}

Status ComponentClientPlayer::getOppositeType() const {
    if (type == BLACK) {
        return WHITE;
    } else {
        return BLACK;
    }
}

bool ComponentClientPlayer::isComp() const{
    return false;
}