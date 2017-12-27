#include "HumanPlayer.h"
#include "ConsoleDisplay.h"
#include <limits>
#include <iostream>
using namespace std;

HumanPlayer::HumanPlayer() {
    type = BLACK;
		displayer = new ConsoleDisplay();
}

HumanPlayer::HumanPlayer(Status t) : type(t){
	displayer = new ConsoleDisplay();
}

HumanPlayer :: ~HumanPlayer() {
	delete[] displayer;
}

Cell HumanPlayer :: doTurn(vector<Cell> options) {
    int i;
    displayer->printChar((char) type);
    displayer->printMessageWitheNewLine(": It's your move.");
    displayer->printMessageWitheNewLine("your possible moves:");

    for (i = 0; i < (int)options.size(); i++) {//getting move from console
    	displayer->printCell(options[i]);
    	displayer->printMessage(" ");
        }
    displayer->printNewLine();
    displayer->printNewLine();

    //validating choice
    int x = 0, y = 0;
    char tempY;
    bool valid = false;
    while (!valid) {
        displayer->printMessageWitheNewLine("Please enter your move row,col: ");
        x = displayer->getInt();
        tempY = displayer->getInt();
        if (tempY == ',') {
        	y = displayer->getInt();
        } else {
        	y = (int) tempY - 48;
        		}

        if (displayer->isInputFailed()) {
            displayer->clearBuffer();
            displayer->ignoreInput('\n');
            displayer->printMessageWitheNewLine("Invalid input!");
            displayer->getBufferContent();
        		}

        for (i = 0; i < (int)options.size(); i++) {
            if (options[i].getRow() == x && options[i].getCol() == y) {
                valid = true;
                break;
            			}
        		}

        if (!valid) {
            displayer->printMessageWitheNewLine("That is not an option.");
            cin.get();
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
