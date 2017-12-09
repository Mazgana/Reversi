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
    int i;
    cout << (char)type << ": It's your move." << endl;
    cout << "your possible moves:" << endl;
    for (i = 0; i < (int)options.size(); i++) {//getting move from console
       cout << "(" << options[i].getRow() << "," << options[i].getCol() << ") ";
        }
    cout << endl << endl;

    //validating choice
    int x = 0, y = 0;
    char tempY;
    bool valid = false;
    while (!valid) {
        cout << "Please enter your move row,col: " << endl;
        cin >> x >> tempY;
        if (tempY == ',') {
        	cin >> y;
        } else {
        	y = (int) tempY - 48;
        		}
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input. !" << endl;
        }
        for (i = 0; i < (int)options.size(); i++) {
            if (options[i].getRow() == x && options[i].getCol() == y) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            cout << "That is not an option." << endl;
        }
    }
    Cell c(x,y);//returning console choice
    return c;
}

Status HumanPlayer :: getChip() const{
    return type;
}

Status HumanPlayer::getOppositeType() const {
	if (type == BLACK) {
		return WHITE;
	} else {
		return BLACK;
	}
}

bool HumanPlayer::isComp() const {
    return false;
}
