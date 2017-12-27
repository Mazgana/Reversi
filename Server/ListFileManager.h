#ifndef SERVER_LISTFILEMANAGER_H
#define SERVER_LISTFILEMANAGER_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> gamesList;

class ListFileManager {
private:
    map<string, int> gamesList;
public:
    bool checkIfExists(string name);
    void addGame(string name);
    void deleteGame(string name);
    int getFirstIdSocket(string name);
    vector<string> getAllGames();
};

#endif //SERVER_LISTFILEMANAGER_H
