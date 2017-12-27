#include "ListGamesCommand.h"
#include <unistd.h>
#include <sys/socket.h>

void ListGamesCommand::execute(string gameName, int socketID) {
    vector<string> gameNames;
    for (auto &it : GameList) {
        gameNames.push_back(it.first);
    }
    for (int i = 0; i < gameNames.size(); i++) {
        int n = send(socketID, gameNames[i].c_str(), gameNames[i].length(), 0);
        if (n == -1) {
            cout << "Error sending name" << endl;
        }
    }
    string end = "\0";
    int m = send(socketID, end.c_str(), end.length(), 0);
    if (m == -1) {
        cout << "Error sending name" << endl;
    }
}
