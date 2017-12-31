#include "HumanPlayer.h"

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

    for (i = 0; i < (int)options.size(); i++) { //getting move from console
    	displayer->printCell(options[i]);
    	displayer->printMessage(" ");
        }
    displayer->printNewLine();
    displayer->printNewLine();

    //validating choice
    int x = 0, y = 0;
    bool valid = false;
    char integers[3];
    string input;

    while (!valid) {
        displayer->printMessageWitheNewLine("Please enter your move row,col: ");
        input = displayer->getString();

        //extracting two integers from the player's choice
        strcpy(integers, input.c_str());
        x = (int) integers[0] - 48;

        if (integers[1] == ',' || integers[1] == ' ') {
        	y = (int) integers[2] - 48;
        } else {
        	y = (int) integers[1] - 48;
        		}

        if (displayer->isInputFailed()) {
            displayer->clearBuffer();
            displayer->ignoreInput('\n');
            displayer->printMessageWitheNewLine("Invalid input!");
            displayer->getBufferContent();
        		}

        //validate that the player's choice is one of the given options
        for (i = 0; i < (int)options.size(); i++) {
            if (options[i].getRow() == x && options[i].getCol() == y) {
                valid = true;
                break;
            			}
        		}

        if (!valid) {
            displayer->printMessageWitheNewLine("That is not an option.");
            displayer->getBufferContent();
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
