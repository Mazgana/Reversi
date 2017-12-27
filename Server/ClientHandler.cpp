
#include "CommandManager.h"
#include "ClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>
#include <sstream>

ClientHandler::ClientHandler(){}

void ClientHandler :: handleClient (int firstClientSocket) {
    int n;
    char buffer[MAX_STR];
    string command = "get_list";

    while(command.compare("get_list")) {
        pthread_mutex_lock(&mutex1);
        long firstClient = (long) firstClientSocket;
        n = recv((int) firstClient, buffer, MAX_STR, 0);
        if (n == -1) {
            cout << "Error reading choice" << endl;
        }

        cout << buffer << endl;

        string input = buffer;

        stringstream ss(input);
        string arg;
        vector<string> tokens;
        while (getline(ss, arg, ' ')) {
            tokens.push_back(arg);
        }

        string gameName = NULL;
        command = tokens[0];
        if (tokens.size() > 0) {
            gameName = tokens[1];
        }
        pthread_mutex_unlock(&mutex1);

        CM.executeCommand(command, gameName, firstClientSocket);
    }
 }