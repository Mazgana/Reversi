#include "CommandManager.h"

CommandManager::CommandManager() {
    commandsMap["start"] = new StartCommand(gamesList);
    commandsMap["list_games"] = new ListGamesCommand();
    commandsMap["join"] = new JoinCommand();
    commandsMap["play"] = new PlayCommand();
    commandsMap["close"] = new CloseCommand();
}

void CommandManager::executeCommand(string command, vector<string> args, int socketID) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}

CommandManager::~CommandManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}