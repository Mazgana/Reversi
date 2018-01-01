#include "ListGamesCommand.h"

void ListGamesCommand::execute(string gameName, int socketID, map<string, int> &GameList) {
    //putting all keys of map into vector of game names
    vector<string> gameNames;
    int len;
    for (map<string,int>::iterator it = GameList.begin(); it != GameList.end(); ++it) {
        gameNames.push_back(it-> first);
    }

    //writing all strings to socket
    for (int i = 0; i < (int) gameNames.size(); i++) {
    	 	len = (int) gameNames[i].length();
    		write(socketID, &len, sizeof(len));
        int n = (int) send(socketID, gameNames[i].c_str(), gameNames[i].length(), 0);
        if (n == -1) {
            cout << "Error sending name" << endl;
        }
    }

    //sending an end of list message to client
    int end = -1;
    int m = (int) write(socketID, &end, sizeof(end));
    if (m == -1) {
        cout << "Error sending name" << endl;
    }
}
