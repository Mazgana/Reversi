/*
 * game manager has holds the function to run the messages
 * received and sent to clients of a reversi game.
 */

#ifndef SERVER_GAMEMANAGER_H
#define SERVER_GAMEMANAGER_H

#include <iostream>
#include <unistd.h>

using namespace std;

class GameManager {
public:
    //gets two socket ID's and passes coordinate messages between them.
    void playGame(int firstClientSocket, int secondClientSocket);
};


#endif //SERVER_GAMEMANAGER_H
