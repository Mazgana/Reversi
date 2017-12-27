
#include "CommandManager.h"
#include "ClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>

#define MAX_STR 12

ClientHandler::ClientHandler(){}

void ClientHandler :: handleClient (int firstClientSocket) {
    int n;
    char buffer[MAX_STR];
    vector<string> args;
//    args.emplace_back("lord");
    long firstClient = (long)firstClientSocket;
    n = read((int)firstClient, &buffer, sizeof(buffer));
    if (n == -1) {
        cout << "Error reading choice" << endl;
    }
    string choice = "start";
    CM.executeCommand(choice, args);
 }