#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H
/*
 * Client class. connects client to server, writes and reads messages to server.
 */
class Client {
public:
    //constructor
    Client(const char *serverIP, int serverPort);

    //connecting current player to server
    void connectToServer();

    //getting the first client to connect in order to determine opening player
    char getOpeningPlayer();

    //send chosen move to other client
    void sendMove(int i, int i1);

    //receive move just done by other client player
    int receiveCoordinate();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //REVERSI_CLIENT_H
