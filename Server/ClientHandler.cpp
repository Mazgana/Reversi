#include <algorithm>
#include "CommandManager.h"
#include "ClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>
#include <sstream>

#define MAX_STR 50

ClientHandler::ClientHandler(){}

void ClientHandler :: handleClient (int firstClientSocket) {
    int n;
    char buffer[MAX_STR] = "";
    vector<string> args;

    cout << "good" << endl;

    long firstClient = (long)firstClientSocket;
    n = recv((int)firstClient, buffer, MAX_STR, 0);
    if (n == -1) {
        cout << "Error reading choice" << endl;
    	}

    string input = buffer;

    cout << input << endl;

    stringstream ss(input);
    string arg;
    vector<string> tokens;
    while (getline(ss, arg, ' ')) {
        args.push_back(arg);
    	}
    string command = args[0];
    args.erase(args.begin());

    cout << "got command from client: " << command << endl;
    CM.executeCommand(command, args, firstClientSocket);
 }
