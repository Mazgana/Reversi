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
    //htons
}