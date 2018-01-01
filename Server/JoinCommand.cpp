#include "JoinCommand.h"

pthread_mutex_t mutex_join_game;

void JoinCommand::execute(string gameName, int socketID, map<string, int> &gameList) {
    pthread_mutex_lock(&mutex_join_game);

    if (gameList.empty()) {//checking if list is empty and noticing client
        int empty = -2;
        int w = (int) write(socketID, &empty, sizeof(empty));
        if (w == -1) {
            cout << "Error writing to socket" << endl;
        }
        pthread_mutex_unlock(&mutex_join_game);
        return;
    }
    if (!gameList.count(gameName)) {//notifying client of invalid game to join
        int fail = -1;
        int w = (int) write(socketID, &fail, sizeof(fail));
        if (w == -1) {
            cout << "Error writing to socket" << endl;
        }
        pthread_mutex_unlock(&mutex_join_game);
        return;
    }

    int firstClientSocket = gameList[gameName];//getting first player's ID

    gameList.erase(gameName);// erasing game from list of available games
    pthread_mutex_unlock(&mutex_join_game);

    int secondClientSocket = socketID;

    ///notifying client game is about to start
    int success = 1;
    int m = (int) write(socketID, &success, sizeof(success));
    cout << "success: " << success << endl;
    if (m == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }

    //starting game
    gameManager.playGame(firstClientSocket, secondClientSocket);

    //closing sockets when game ends
    close(firstClientSocket);
    close(secondClientSocket);
}
