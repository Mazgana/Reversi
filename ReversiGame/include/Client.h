#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H

#include "ConsoleDisplay.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_STR 50

using namespace std;

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

    //sending to the server a message to approve that this client is still connected
    void attending();

    //receiving the game's list form the server
    vector<string> receiveStringList(string messageToServer);

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;

		Display* displayer;
};

#endif //REVERSI_CLIENT_H
