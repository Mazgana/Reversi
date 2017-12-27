#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H

#define MAX_STR 50

#include <map>
static map<string, int> GameList;

class ClientHandler {
private:
    vector<pthread_t> threads;
    CommandManager CM;

public:
    ClientHandler();

    void getChoice(void* firstClientSocket);

    void handleClient(int firstClientSocket);

    void createNewThread(int socketId);
};


#endif //SERVER_CLIENTHANDLER_H
