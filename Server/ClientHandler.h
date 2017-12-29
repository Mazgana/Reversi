#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H

#include <map>
#include <algorithm>
#include "CommandManager.h"
#include <cstring>
#include <sstream>

#define MAX_STR 50

static map <string, int> GameList;
//extern pthread_mutex_t mutex_map_games;

class ClientHandler {
private:
    vector<pthread_t> threads;
    CommandManager CM;

public:
    ClientHandler();

    void handleClient(int firstClientSocket);

    void createNewThread(int socketId);
};


#endif //SERVER_CLIENTHANDLER_H
