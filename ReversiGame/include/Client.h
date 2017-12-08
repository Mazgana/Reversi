//
// Created by leah on 03/12/17.
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H

class Client {
public:
    Client(const char *serverIP, int serverPort);
    void connectToServer();

    char getOpeningPlayer();

    void sendMove(int i, int i1);

    int receiveCoordinate();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //REVERSI_CLIENT_H
