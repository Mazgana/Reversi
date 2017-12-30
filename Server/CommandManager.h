/*
 * command manager class holds command list and matches string command to command object to be executed.
 */
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
    map<string, Command *> commandsMap;
public:
    //constructor.
    CommandManager();
    //destructor.
    ~CommandManager();

    //call matching command to string and send needed arguments for execution.
    void executeCommand(string command, string gameName, int socketID, map<string, int> &gameList);
};

#endif //SERVER_COMMANDMANAGER_H
