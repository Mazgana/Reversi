#ifndef SERVER_COMMANDMANAGER_H
#define SERVER_COMMANDMANAGER_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "Command.h"
#include "StartCommand.h"

using namespace std;

static map<string, int> GameList;

class CommandManager {
private:
//    vector<string> gamesList;
    map<string, Command *> commandsMap;
public:
    CommandManager();
    ~CommandManager();
    void executeCommand(string command, string gameName, int socketID);
};

#endif //SERVER_COMMANDMANAGER_H
