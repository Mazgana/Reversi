#include "ClientHandler.h"

void *handleClient1(void *clientSocket) {
    //calling first function of new thread
    ClientHandler ch;
    long tid = (long)clientSocket;
    cout << "Hello world. It's me, thread " << tid << endl;
    ch.handleClient((int)tid);
}

void ClientHandler :: createNewThread(int clientSocket) {
	//creating the new thread
    pthread_t thread;
	int rc = pthread_create(&thread, NULL, handleClient1, (void *)(long)clientSocket);
	if (rc == -1) {
		throw "Failed creating thread";
	}
}

void ClientHandler :: handleClient (int clientSocket) {
    int n;
    int firstClientSocket = clientSocket;

    while (true) {//loop to get another command after previous was executed
        //getting string command from client
        char buffer[MAX_STR] = "";
        long firstClient = (long) firstClientSocket;
        n = (int) recv((int) firstClient, buffer, MAX_STR, 0);
        if (n == -1) {
            cout << "Error reading choice" << endl;
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

        //executing the command
        CM.executeCommand(command, gameName, firstClientSocket, GameList);

        //ending loop when command is close
        if (!command.compare("close")) {
            break;
        }
    }
 }
