#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H

#define MAX_STR 50

class ClientHandler {
private:
    vector<pthread_t> threads;
    CommandManager CM;

public:
    ClientHandler();

    void getChoice(void* firstClientSocket);

    void handleClient(int firstClientSocket);
};


#endif //SERVER_CLIENTHANDLER_H
