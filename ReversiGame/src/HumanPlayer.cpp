#include "HumanPlayer.h"
#include <limits>
#include <iostream>
using namespace std;

HumanPlayer::HumanPlayer() {
    type = BLACK;
}

HumanPlayer::HumanPlayer(Status t) : type(t){
}

Cell HumanPlayer :: doTurn(vector<Cell> options) {
    int i, j;
    bool repeat = false;
    cout << type << ": It's your move." << endl;
    cout << "your possible moves:" << endl;
    for (i = 0; i < (int)options.size(); i++) {
        for (j = 0; j < i; j++) {
            if (options[i].getCol() == options[j].getCol() && options[i].getRow() == options[j].getRow()) {
                repeat = true;
            }
        }//printing options
        if (!repeat) {
            cout << "(" << options[i].getCol() << "," << options[i].getRow() << ") ";
        }
        repeat = false;
    }
    cout << endl << endl;

    int x = 0, y = 0;
    bool valid = false;
    while (!valid) {
        cout << "Please enter your move row,col: " << endl;
        char dumb;
        cin >> x >> dumb >> y;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input. !" << endl;
        }
        for (i = 0; i < options.size(); i++) {
            if (options[i].getCol() == x && options[i].getRow() == y) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            cout << "That is not an option." << endl;
        }
    }
    Cell c(x,y);
    return c;
}

Status HumanPlayer :: getChip() const{
    return type;
}

Status HumanPlayer::getOppositeType() {
	if (type == BLACK) {
		return WHITE;
	} else {
		return BLACK;
	}
}
