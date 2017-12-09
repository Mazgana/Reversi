#include <iostream>
#include <limits>
#include "ClientPlayer.h"

using namespace std;

ClientPlayer::ClientPlayer(Client client) : contactServer(client) {
    type = BLACK;
}

ClientPlayer::ClientPlayer(Status t, Client client) : type(t), contactServer(client) {
}

Cell ClientPlayer :: doTurn(vector<Cell> options) {
    int i;
    cout << (char)type << ": It's your move." << endl;
    cout << "your possible moves:" << endl;
    for (i = 0; i < (int)options.size(); i++) {
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
    cout << "You have got no moves. Turn passes to " << (char) getOppositeType() << endl;
    cout << "press enter to continue.." << endl;
    cin.get();
    //sending random move so server knows to skip turn.
    contactServer.sendMove(10,10);
}