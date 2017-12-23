#ifndef SERVER_COMMANDMANAGER_H
#define SERVER_COMMANDMANAGER_H


#include <map>
#include "Command.h"
class CommandManager {
public:
    CommandManager();
    ~CommandManager();
    void executeCommand(string command,
                        vector<string> args);
private:
    map<string, Command *> commandsMap;
};

#endif //SERVER_COMMANDMANAGER_H
