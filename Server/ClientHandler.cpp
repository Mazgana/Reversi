#include "ClientHandler.h"

ClientHandler::ClientHandler(){}

void *handleClient1(void *clientSocket) {
    ClientHandler ch;
    long tid = (long)clientSocket;
    cout << "Hello world. It's me, thread " << tid << endl;
    ch.handleClient((int)tid);
}

void ClientHandler :: createNewThread(int clientSocket) {
	pthread_t thread;
	int rc = pthread_create(&thread, NULL, handleClient1, (void *)(long)clientSocket);
	if (rc == -1) {
		throw "Failed creating thread";
	}
}

void ClientHandler :: handleClient (int clientSocket) {
    int n;
    string value = "list_games ";
    int firstClientSocket = clientSocket;

//    while(!value.compare("list_games ")) {
    while (true) {
        char buffer[MAX_STR] = "";
        long firstClient = (long) firstClientSocket;
        n = recv((int) firstClient, buffer, MAX_STR, 0);
        if (n == -1) {
            cout << "Error reading choice" << endl;
        		}

        string input = buffer;
        stringstream ss(input);
        string arg;
        vector<string> tokens;
        while (getline(ss, arg, ' ')) {
            tokens.push_back(arg);
        		}

        string gameName = "";
        string command = tokens[0];
        if (tokens.size() > 1) {
            gameName = tokens[1];
        		}

        CM.executeCommand(command, gameName, firstClientSocket, GameList);

        value = command.append(" ");

        if (value.compare("close ")) {
            break;
        }
    }
 }
