#include "JoinCommand.h"

pthread_mutex_t mutex_join_game;

void JoinCommand::execute(string gameName, int socketID, map<string, int> &gameList) {
    pthread_mutex_lock(&mutex_join_game);

    if (gameList.empty()) {//checking if list is empty and notifying client
        int empty = -2;
        writeToSocket(socketID, empty);
        pthread_mutex_unlock(&mutex_join_game);
        return;
    	}
    if (!gameList.count(gameName)) {//notifying client of invalid game to join
        int fail = -1;
        writeToSocket(socketID, fail);
        pthread_mutex_unlock(&mutex_join_game);
        return;
    	}

    int firstClientSocket = gameList[gameName];//getting first player's ID

    gameList.erase(gameName);// erasing game from list of available games
    pthread_mutex_unlock(&mutex_join_game);

    int secondClientSocket = socketID;

    ///notifying client game is about to start
    int success = 1;
    writeToSocket(socketID, success);

    //starting game
    gameManager.playGame(firstClientSocket, secondClientSocket);

    //closing sockets when game ends
    close(firstClientSocket);
    close(secondClientSocket);
//    pthread_exit(NULL);
}

int JoinCommand::writeToSocket(int socket, int message) {
    int w = (int) write(socket, &message, sizeof(message));
    if (w == -1) {
        cout << "Error writing to socket" << endl;
    }
    return w;
}
