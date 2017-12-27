#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H

#include "Display.h"
/*
 * Client class. connects client to server, writes and reads messages to server.
 */
class Client {
private:
	Display* displayer;

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

    int sendCommandMessage(std::string message);

    //receive move just done by other client player
    int receiveCoordinate();

    void attending(int mes);

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //REVERSI_CLIENT_H