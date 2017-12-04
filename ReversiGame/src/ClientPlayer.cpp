#include "ClientPlayer.h"

using namespace std;

ClientPlayer::ClientPlayer() {
    type = BLACK;
}

ClientPlayer::ClientPlayer(Status t) : type(t){
}

Cell ClientPlayer :: doTurn(vector<Cell> options) {

}

Status ClientPlayer :: getChip() const{
    return type;
}

Status ClientPlayer::getOppositeType() const {
    if (type == BLACK) {
        return WHITE;
    } else {
        return BLACK;
    }
}

bool ClientPlayer::isComp() const{
    return false;
}
