#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H

#include "Display.h"

#define MAX_STR 50

/*
 * Client class. connects client to server, writes and reads messages to server.
 */
class Client {
public:
    //constructor
    Client(const char *serverIP, int serverPort);
    ~Client();

    //connecting current player to server
    void connectToServer();

    //getting the first client to connect in order to determine opening player
    char getOpeningPlayer();

    //send chosen move to other client
    void sendMove(int i, int i1);

    int sendCommandMessage(string message);

    //receive move just done by other client player
    int receiveCoordinate();

    void attending(int mes);

    vector<string> reciveStringList(string messageToServer);

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;

		Display* displayer;
};

#endif //REVERSI_CLIENT_H