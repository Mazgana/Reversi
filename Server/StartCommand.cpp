#include "StartCommand.h"

pthread_mutex_t mutex_start_game;

void StartCommand::execute(string gameName, int socketID, map<string, int> &GameList) {
    pthread_mutex_lock(&mutex_start_game);

    //if game is already in list, send fail message and return
    if(GameList.count(gameName)) {
        int fail = -1;
        int w = (int) write(socketID, &fail, sizeof(fail));
        if (w == -1) {
            cout << "Error writing to socket" << endl;
            pthread_mutex_unlock(&mutex_start_game);
            return;
        		}
        pthread_mutex_unlock(&mutex_start_game);
        return;
    }

    //if game was not in list, add it
    GameList[gameName] = socketID;

    //sending success message to client
    int success = 1;
    int m = (int) write(socketID, &success, sizeof(success));
    if (m == -1) {
        cout << "Error writing to socket" << endl;
        return;
    	}
    pthread_mutex_unlock(&mutex_start_game);

    //terminating current thread while waiting for game to start (socket saved in map)
    pthread_exit(NULL);
}
