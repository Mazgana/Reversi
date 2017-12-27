#include <algorithm>
#include "CommandManager.h"
#include "ClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>
#include <sstream>

ClientHandler::ClientHandler(){}

void ClientHandler :: handleClient (int clientSocket) {
    int n;
    char buffer[MAX_STR] = "";
    string value = "list_games ";
    int firstClientSocket = clientSocket;

    while(!value.compare("list_games ")) {
        cout << "handling" << firstClientSocket << endl;

        long firstClient = (long) firstClientSocket;
        n = recv((int) firstClient, buffer, MAX_STR, 0);
        if (n == -1) {
            cout << "Error reading choice" << endl;
        		}

        string input = buffer;

        cout << "full input: " << input << endl;

        stringstream ss(input);
        cout << "ss " << ss << endl;
        string arg;
        vector<string> tokens;
        while (getline(ss, arg, ' ')) {
            tokens.push_back(arg);
            cout << "arg: " << arg << endl;

        }

        string gameName = "";
        cout << "game name: " << gameName << endl;
        string command = tokens[0];
        if (tokens.size() > 1) {
            gameName = tokens[1];
        }

        cout << "got command from client: " << command << endl;

        CM.executeCommand(command, gameName, firstClientSocket);

        value = command;
    }
 }
