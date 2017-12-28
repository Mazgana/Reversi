#ifndef SERVER_COMMANDMANAGER_H
#define SERVER_COMMANDMANAGER_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "Command.h"
#include "StartCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"

using namespace std;

class CommandManager {
private:
//    vector<string> gamesList;
    map<string, Command *> commandsMap;
public:
    CommandManager();
    ~CommandManager();
    void executeCommand(string command, string gameName, int socketID, map<string, int> &gameList);
};

#endif //SERVER_COMMANDMANAGER_H
