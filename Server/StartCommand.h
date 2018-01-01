/*
 * the start command class saves game and id of first player into the game list.
 */
#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H

#include "Command.h"
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_STR 50

//pthread_mutex_t start_mutex;

class StartCommand: public Command {
public:
    //constructor.
    StartCommand(){};
    //executes command. (params as in interface).
    // checks if new name is already in list, else adds it with the ID as value to game name key.
    void execute(string gameName, int socketID, map<string, int> &gameList);
};

#endif //SERVER_STARTCOMMAND_H
