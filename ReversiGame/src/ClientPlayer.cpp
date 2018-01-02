#include "ClientPlayer.h"

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

Cell ClientPlayer :: doTurn(vector<Cell> options, int maxWidth, int maxLength) {
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
    bool valid = false;
    while (!valid) {
    		displayer->printMessageWitheNewLine("Please enter your move row,col: ");
    		input = displayer->getString();

    		if (!close.compare(input)) { //the player closed the game
    			x = -5;
    			y = -5;
    			break;
    		} else { //extracting two integers from the user's input
					strcpy(integers, input.c_str());
					x = (int) integers[0] - 48;
					if (integers[1] == ',') {
						y = (int) integers[2] - 48;
					} else {
						y = (int) integers[1] - 48;
					}

					if (0 > x || x > maxWidth || y < 0 || y > maxLength) {
						displayer->clearBuffer();
						displayer->ignoreInput('\n');
						displayer->printMessageWitheNewLine("Invalid input!");
						displayer->clearBuffer();
					} else {
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
    		}
    	}
    Cell c(x,y); //returning the client's choice
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
	 	 //sending random move so the server and the other player will know that the game ended.
	 	 contactServer.sendMove(-3, -3);
 }
