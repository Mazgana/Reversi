/*
 * class to handle client- gets socket ID and reads commands from client, sending them to manager.
 */
#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H

#include <map>
#include <algorithm>
#include "CommandManager.h"
#include <cstring>
#include <sstream>

#define MAX_STR 50

static map <string, int> GameList;
extern pthread_mutex_t mutex_join_game;
extern pthread_mutex_t mutex_start_game;

class ClientHandler {
private:
    //command manger to send all string commands to.
    CommandManager CM;

public:
    //constructor
    ClientHandler(){};

    //gets client socket as param
    //gets command from client as string and passes to cm.
    void handleClient(int firstClientSocket);

    //creates new thread for new client connection.
//    void createNewThread(int socketId);
};


#endif //SERVER_CLIENTHANDLER_H
