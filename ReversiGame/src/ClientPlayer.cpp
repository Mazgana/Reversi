#include <iostream>
#include <limits>
#include <sstream>
#include "ClientPlayer.h"
#include "ConsoleDisplay.h"

using namespace std;

ClientPlayer::ClientPlayer(Client client) : contactServer(client) {
		displayer = new ConsoleDisplay();
    type = BLACK;
}

ClientPlayer::ClientPlayer(Status t, Client client) : type(t), contactServer(client) {
	displayer = new ConsoleDisplay();
}

ClientPlayer :: ~ClientPlayer() {
	delete[] displayer;
}

Cell ClientPlayer :: doTurn(vector<Cell> options) {
    int i;
    displayer->printChar((char) type);
    displayer->printMessageWitheNewLine(": It's your move.");
    displayer->printMessageWitheNewLine("your possible moves:");
    for (i = 0; i < (int)options.size(); i++) {
    	displayer->printCell(options[i]);
    	displayer->printMessage(" ");
    }
    displayer->printNewLine();
    displayer->printNewLine();

    //validating choice
    string input;
    string close = "close";
    char integers[3];

    int x = 0, y = 0;
    char tempY;
    bool valid = false;
    while (!valid) {
    		displayer->printMessageWitheNewLine("Please enter your move row,col: ");
    		input = displayer->getString();

    		if (!close.compare(input)) {
    				x = -5;
    				y = -5;
    				break;
    		} else {

					strcpy(integers, input.c_str());
					x = (int) integers[0] - 48;
					if (integers[1] == ',') {
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
    }
    Cell c(x,y);//returning console choice
    contactServer.sendMove(x,y);
    return c;
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

void ClientPlayer::skipTurn() {
		displayer->printMessage("You have got no moves. Turn passes to ");
		displayer->printChar((char) getOppositeType());
		displayer->printNewLine();

		displayer->printMessageWitheNewLine("press enter to continue..");
		displayer->getBufferContent();

    //sending random move so server knows to skip turn.
    contactServer.sendMove(-2,-2);
}

 void ClientPlayer::endGame() {
	 	 contactServer.sendMove(-3, -3);
 }
