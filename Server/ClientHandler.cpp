
#include "CommandManager.h"
#include "ClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>
#include <sstream>

#define MAX_STR 50

pthread_mutex_t mutex1;

ClientHandler::ClientHandler(){}

void ClientHandler :: handleClient (int firstClientSocket) {
    int n;
    char buffer[MAX_STR];
    vector<string> args;

    long firstClient = (long)firstClientSocket;
    n = recv((int)firstClient, buffer, MAX_STR, 0);
    if (n == -1) {
        cout << "Error reading choice" << endl;
    }

    cout << buffer << endl;

    string input = buffer;

    stringstream ss(input);
    string arg;
    vector<string> tokens;
    while (getline(ss, arg, ' ')) {
        args.push_back(arg);
    }

    pthread_mutex_lock(&mutex1);
    string command = args[0];
    args.erase(args.begin());
    pthread_mutex_unlock(&mutex1);

    CM.executeCommand(command, args, firstClientSocket);
 }