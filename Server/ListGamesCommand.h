#ifndef SERVER_LISTGAMESCOMMAND_H
#define SERVER_LISTGAMESCOMMAND_H

#include "Command.h"
#include <map>

class ListGamesCommand: public Command {

public:
		ListGamesCommand();
    void execute(string gameName, int socketID, map<string, int> &gameList);
};

#endif //SERVER_LISTGAMESCOMMAND_H
