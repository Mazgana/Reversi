#include "JoinCommand.h"

JoinCommand::JoinCommand(){};

void JoinCommand::execute(string gameName, int socketID, map<string, int> &gameList) {
    string name = gameName;
    if(!gameList.count(name)) {
        int fail = -1;
        int w = write(socketID, &fail, sizeof(fail));
        if (w == -1) {
            cout << "Error writing to socket" << endl;
        }
        return;
    }

    int firstClientSocket = gameList[name];
    int secondClientSocket = socketID;
    gameList.erase(name);

    int success = 1;
    int m = write(socketID, &success, sizeof(success));
    if (m == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }

    int firstClient = 1;
    int secondClient = 2;

    int x = write(firstClientSocket, &firstClient, sizeof(firstClient));
    int o = write(secondClientSocket, &secondClient, sizeof(secondClient));

    if (x == -1 || o == -1)
        throw "Error in sending the clients messages.";

    playGame(firstClientSocket, secondClientSocket);

    close(firstClientSocket);
    close(secondClientSocket);
}

void JoinCommand::playGame(int firstClientSocket, int secondClientSocket) {
    int arg1, arg2, n, dumb;
    int disconnection = -4;

    while (true) {
        // Read new coordinate arguments from player
        n = read(firstClientSocket, &arg1, sizeof(arg1));
        if (n == -1) {
            cout << "Error reading arg1" << endl;
            return;
        }

        if (arg1 == -3)
            return;

        if (n == 0) {
            write(secondClientSocket, &disconnection, sizeof(disconnection));
            cout << "Client 1 disconnected" << endl;
            return;
        }

        n = read(firstClientSocket, &arg2, sizeof(arg2));
        if (n == -1) {
            cout << "Error reading arg2" << endl;
            return;
        }

        // Write the result coordinates back to the client
        int w = write(secondClientSocket, &arg1, sizeof(arg1));

        if (w == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }

        int check = read(secondClientSocket, &dumb, sizeof(dumb));

        if (check == 0) {
            write(firstClientSocket, &disconnection, sizeof(disconnection));
            cout << "Client 2 disconnected" << endl;
            return;
        }

        int m = write(secondClientSocket, &arg2, sizeof(arg2));
        if (m == -1) { //Client disconnected
            write(firstClientSocket, &disconnection, sizeof(disconnection));
            return;
        }

        //swapping the clients
        int temp = firstClientSocket;
        firstClientSocket = secondClientSocket;
        secondClientSocket = temp;
    }
}