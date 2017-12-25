#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H


class ClientHandler {
private:
    vector<pthread_t> threads;
    CommandManager CM;
    vector<string> gamesList;

public:
    ClientHandler();

    void *getChoice(void* firstClientSocket);

    void handleClient(int firstClientSocket);
};


#endif //SERVER_CLIENTHANDLER_H
