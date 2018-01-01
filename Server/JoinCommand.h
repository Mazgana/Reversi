/*
 * join command class is the command that enables a player to join a game that was declared by another
 * and the starting of that game.
 */
#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H

#include <unistd.h>
#include "Command.h"
#include "GameManager.h"

class JoinCommand: public Command {
private:
    GameManager gameManager;
public:
    //constructor
    JoinCommand(){};

    // gets game name, ID of current client and the list of games started.
    // call game manager with both Id related to game(if exists in the game list) and caller ID.
    // removes the game from list.
    void execute(string gameName, int socketID, map<string, int> &gameList);
};


#endif //SERVER_JOINCOMMAND_H
