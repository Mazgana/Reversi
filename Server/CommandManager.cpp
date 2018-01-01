#include "CommandManager.h"

CommandManager::CommandManager() {
    //creating map to associate between command string and the object
    commandsMap["start"] = new StartCommand();
    commandsMap["list_games"] = new ListGamesCommand();
    commandsMap["join"] = new JoinCommand();
}

void CommandManager::executeCommand(string command, string gameName, int socketID, map<string, int> &gameList) {
    Command *commandObj = commandsMap[command];//getting the command object
    commandObj->execute(gameName, socketID, gameList);//executing given command
}

CommandManager::~CommandManager() {
    // going over map and releasing/deleting al mmemory
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}
