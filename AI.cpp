#include "AI.h"
#include <limits>
#include <iostream>
using namespace std;

AI::AI() {
    type = BLACK;
}

AI::AI(Status t) : type(t){
}

Cell AI :: doTurn(vector<Cell> options) {
		int i;

		for (i = 0; i < options.size(); i++) {

		}
		Cell c(x,y);
    return c;
}

Status AI :: getChip() const{
    return type;
}

Status AI::getOppositeType() {
	if (type == BLACK) {
		return WHITE;
	} else {
		return BLACK;
	}
}
