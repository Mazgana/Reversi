/*
 * this command return the list of games started to client.
 */
#ifndef SERVER_LISTGAMESCOMMAND_H
#define SERVER_LISTGAMESCOMMAND_H

#include "Command.h"
#include <map>
#include <unistd.h>
#include <sys/socket.h>

class ListGamesCommand: public Command {
public:
	//constructor.
	ListGamesCommand();
    // gets parameter like other command interface commands.
	// sends client ID strings of all game names in game list.
	void execute(string gameName, int socketID, map<string, int> &gameList);
};

#endif //SERVER_LISTGAMESCOMMAND_H
