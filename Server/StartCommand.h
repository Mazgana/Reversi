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
    StartCommand();
    void execute(string gameName, int socketID, map<string, int> &gameList);
};

#endif //SERVER_STARTCOMMAND_H
