#include "CommandManager.h"

CommandManager::CommandManager() {
    commandsMap["start"] = new StartCommand();
    commandsMap["list_games"] = new ListGamesCommand();
    commandsMap["join"] = new JoinCommand();
//    commandsMap["play"] = new PlayCommand();
//    commandsMap["close"] = new CloseCommand();
}

void CommandManager::executeCommand(string command, string gameName, int socketID, map<string, int> &gameList) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(gameName, socketID, gameList);
}

CommandManager::~CommandManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}
