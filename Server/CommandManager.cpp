#include "CommandManager.h"

CommandManager::CommandManager() {
    commandsMap["print"] = new PrintCommand();
    commandsMap["start"] = new StartCommand();
    commandsMap["list_games"] = new StartCommand();
    commandsMap["join"] = new StartCommand();
    commandsMap["play"] = new StartCommand();
    commandsMap["close"] = new StartCommand();
}

void CommandManager::executeCommand(string
                                     command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}

CommandManager::~CommandManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it !=
                                   commandsMap.end(); it++) {
        delete it->second;
    }
}