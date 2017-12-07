#include "Client.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

using namespace std;

Client::Client(const char *serverIP, int serverPort): serverIP(serverIP), serverPort(serverPort), clientSocket(0){
    cout << "Client" << endl;
}

void Client::connectToServer() {
    //create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket == -1) {
        throw "Error opening socket";
    }
    //Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw  "Can't parse IP address";
    }
    // Get a hostest structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof address, AF_INET);
    if(server == NULL) {
        throw "Host is unreachable";
    }
    //Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));

    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    //htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);

    //Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;
}

int Client::sendExercise(int arg1, char op, int arg2) {
    //Write the exercise arguments to the socket
    int n = write(clientSocket, &arg1, sizeof(arg1));
    if (n == -1) {
        throw "Error writing arg1 to socket";
    }
    n = write(clientSocket, &op, sizeof(arg1));
    if (n == -1) {
        throw "Error writing op to socket";
    }
    n = write(clientSocket, &arg2, sizeof(arg1));
    if (n == -1) {
        throw "Error writing arg2 to socket";
    }

    // Read the result from the server
    int result;
    n = read(clientSocket, &result, sizeof(result));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    return result;
}

char Client::getOpeningPlayer() {
    int playersPlace;
    int n = read(clientSocket, &playersPlace, sizeof(playersPlace));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    if(playersPlace == 1) {
        cout << "You are the black player X, you go first" << endl;
        return 'X';
    } else if (playersPlace == 2) {
        cout << "You are the white player O, you go second" << endl;
        return 'O';
    } else {
        cout << "got unreadable starting player from server" << endl;
        return ' ';
    }
}

int Client::receiveCoordinate() {
    int cor;
    int n = read(clientSocket, &cor, sizeof(cor));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    return cor;
}

void Client::sendMove(int x, int y) {
    int n = write(clientSocket, &x, sizeof(x));
    if (n == -1) {
        throw "Error writing x to socket";
    }
    n = write(clientSocket, &y, sizeof(y));
    if (n == -1) {
        throw "Error writing y to socket";
    }
}