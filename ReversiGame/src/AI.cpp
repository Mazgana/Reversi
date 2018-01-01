#include "AI.h"

AI::AI() {
    type = BLACK;
}

AI::AI(Status t) : type(t){
}

Cell AI :: doTurn(vector<Cell> options, int maxWidth, int maxLength) {
		Cell c;
    return c;
}

Status AI :: getChip() const{
    return type;
}

Status AI::getOppositeType() const {
	if (type == BLACK) {
		return WHITE;
	} else {
		return BLACK;
	}
}

bool AI::isComp() const{
    return true;
}
