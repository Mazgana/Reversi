#ifndef SERVER_LISTGAMESCOMMAND_H
#define SERVER_LISTGAMESCOMMAND_H

#include "Command.h"
#include <map>
#include <unistd.h>
#include <sys/socket.h>

class ListGamesCommand: public Command {

public:
		ListGamesCommand();
    void execute(string gameName, int socketID, map<string, int> &gameList);
};

#endif //SERVER_LISTGAMESCOMMAND_H
