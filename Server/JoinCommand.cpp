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
    gameList.erase(name);
    pthread_mutex_unlock(&mutex_join_game);

    int secondClientSocket = socketID;

    int success = 1;
    int m = write(socketID, &success, sizeof(success));
    cout << "success: " << success << endl;
    if (m == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }

    gameManager.playGame(firstClientSocket, secondClientSocket);

    close(firstClientSocket);
    close(secondClientSocket);
}
