#include "ListGamesCommand.h"
#include <unistd.h>
#include <sys/socket.h>
#include <map>

ListGamesCommand :: ListGamesCommand() {

}

void ListGamesCommand::execute(string gameName, int socketID, map<string, int> &GameList) {
    vector<string> gameNames;
    for(map<string,int>::iterator it = GameList.begin(); it != GameList.end(); ++it) {
        gameNames.push_back(it-> first);
    }
    cout << "in list command, for socket: " << socketID << endl;
    cout << "Map size: " << GameList.size() << endl;
    for (int i = 0; i < (int) gameNames.size(); i++) {
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
