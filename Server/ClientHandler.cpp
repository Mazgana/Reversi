#include "ClientHandler.h"

void ClientHandler :: handleClient (int clientSocket) {
    int n;
    int firstClientSocket = clientSocket;
    bool run = true;

        //getting string command from client
        char buffer[MAX_STR] = "";
        long firstClient = (long) firstClientSocket;

        n = (int) recv((int) firstClient, buffer, MAX_STR, 0);
        if (n == -1) {
            throw "Error reading choice";
        }

        //splitting command to command name and other argument
        string input = buffer;
        stringstream ss(input);
        string arg;
        vector<string> tokens;
        while (getline(ss, arg, ' ')) {
            tokens.push_back(arg);
        		}

        string gameName = "";
        string command = tokens[0];//putting first arg as command
        if (tokens.size() > 1) {
            gameName = tokens[1];//secong arg as game name
        		}

    cout << "executing command..: " << command << endl;
        //executing the command
    CM.executeCommand(command, gameName, firstClientSocket, GameList);
 }
