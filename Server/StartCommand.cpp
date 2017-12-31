#include "StartCommand.h"

pthread_mutex_t mutex_map_games;

StartCommand::StartCommand(){};

void StartCommand::execute(string gameName, int socketID, map<string, int> &GameList) {
    string name = gameName;
    if(GameList.count(name)) {
        int fail = -1;
        int w = write(socketID, &fail, sizeof(fail));
        if (w == -1) {
            cout << "Error writing to socket" << endl;
            return;
        		}

        return;
    	}

    GameList[name] = socketID;

    int success = 1;
    int m = write(socketID, &success, sizeof(success));
    if (m == -1) {
        cout << "Error writing to socket" << endl;
        return;
    	}

    pthread_exit(NULL);
}
