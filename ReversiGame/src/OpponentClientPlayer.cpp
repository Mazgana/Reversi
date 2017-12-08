#include <iostream>
#include "OpponentClientPlayer.h"

using namespace std;

OpponentClientPlayer::OpponentClientPlayer(Client client) : messageReceiver(client) {
    type = WHITE;
}

OpponentClientPlayer::OpponentClientPlayer(Status t, Client client) : type(t), messageReceiver(client) {
}

Cell OpponentClientPlayer :: doTurn(vector<Cell> options) {
    int x,y;
    cout << "Waiting for opponent to play turn..." << endl;
    x = messageReceiver.receiveCoordinate();
    y = messageReceiver.receiveCoordinate();
    Cell c(x,y);
    cout << (char) getChip() << " played ";
    c.printCell();
    cout << endl;
    return c;
}

Status OpponentClientPlayer :: getChip() const{
    return type;
}

Status OpponentClientPlayer::getOppositeType() const {
    if (type == BLACK) {
        return WHITE;
    } else {
        return BLACK;
    }
}

bool OpponentClientPlayer::isComp() const{
    return false;
}

void OpponentClientPlayer::skipTurn() {
    cout << "Waiting for opponent to play turn..." << endl;
    int dump = messageReceiver.receiveCoordinate();
    dump = messageReceiver.receiveCoordinate();
    cout << "opponnent ";
    cout << (char) getChip() << " had no moves." << endl;
}