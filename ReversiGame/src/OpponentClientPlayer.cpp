#include <iostream>
#include "OpponentClientPlayer.h"
#include "ConsoleDisplay.h"

using namespace std;

OpponentClientPlayer::OpponentClientPlayer(Client client) : messageReceiver(client) {
		displayer = new ConsoleDisplay();
    type = WHITE;
}

OpponentClientPlayer::OpponentClientPlayer(Status t, Client client) : type(t), messageReceiver(client) {
	displayer = new ConsoleDisplay();
}

OpponentClientPlayer :: ~OpponentClientPlayer() {
	delete[] displayer;
}

Cell OpponentClientPlayer :: doTurn(vector<Cell> options) {
    int x,y;

    //reading two integers that will represent coordinates
    x = messageReceiver.receiveCoordinate();
    messageReceiver.attending(1);
    y = messageReceiver.receiveCoordinate();

    if (x != -5)
    	displayer->printMessageWitheNewLine("Waiting for opponent to play turn...");

    Cell c(x,y);
    if (x != -4 && x != -5) { //The opponent player disconnected or closed the game
    	displayer->printChar((char) getChip());
    	displayer->printMessage(" played ");
			displayer->printCell(c);
			displayer->printNewLine();
    	}
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
    displayer->printMessageWitheNewLine("Waiting for opponent to play turn...");

    //reading two integers and dumping them, so server knows to skip turn
    messageReceiver.receiveCoordinate();
    messageReceiver.attending(1);
    messageReceiver.receiveCoordinate();

    displayer->printMessage("opponent ");
    displayer->printChar((char) getChip());
    displayer->printMessageWitheNewLine(" had no moves.");
}
