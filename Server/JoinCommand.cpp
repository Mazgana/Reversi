#include "JoinCommand.h"

pthread_mutex_t mutex_join_game;

JoinCommand::JoinCommand(){};

void JoinCommand::execute(string gameName, int socketID, map<string, int> &gameList) {

    string name = gameName;

    pthread_mutex_lock(&mutex_join_game);
    if(!gameList.count(name)) {
        int fail = -1;
        int w = write(socketID, &fail, sizeof(fail));
        if (w == -1) {
            cout << "Error writing to socket" << endl;
        		}
        return;
    	}

    int firstClientSocket = gameList[name];
    pthread_mutex_unlock(&mutex_join_game);

    cout << "first: " << firstClientSocket << endl;
    int secondClientSocket = socketID;
    cout << "second: " << secondClientSocket << endl;
    gameList.erase(name);

    int success = 1;
    int m = write(socketID, &success, sizeof(success));
    cout << "success: " << success << endl;
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
