#include "ListGamesCommand.h"

ListGamesCommand :: ListGamesCommand() {}

void ListGamesCommand::execute(string gameName, int socketID, map<string, int> &GameList) {
    vector<string> gameNames;
    int len;
    for (map<string,int>::iterator it = GameList.begin(); it != GameList.end(); ++it) {
        gameNames.push_back(it-> first);
    	}

    for (int i = 0; i < (int) gameNames.size(); i++) {
    	 	len = gameNames[i].length();
    		write(socketID, &len, sizeof(len));
        int n = send(socketID, gameNames[i].c_str(), gameNames[i].length(), 0);
        if (n == -1) {
            cout << "Error sending name" << endl;
        		}
    	}

    int end = -1;
    int m = write(socketID, &end, sizeof(end));
    if (m == -1) {
        cout << "Error sending name" << endl;
    }
}
