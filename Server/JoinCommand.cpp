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

    gameManager.playGame(firstClientSocket, secondClientSocket);

    close(firstClientSocket);
    close(secondClientSocket);
}