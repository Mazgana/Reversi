#ifndef SERVER_COMMANDMANAGER_H
#define SERVER_COMMANDMANAGER_H


#include <map>
#include "Command.h"
#include "StartCommand.h"

class CommandManager {
private:
    vector<string> gamesList;
    map<string, Command *> commandsMap;
public:
    CommandManager();
    ~CommandManager();
    void executeCommand(string command, string gameName, int socketID);
};

#endif //SERVER_COMMANDMANAGER_H
