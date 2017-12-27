#ifndef SERVER_LISTGAMESCOMMAND_H
#define SERVER_LISTGAMESCOMMAND_H

#include "Command.h"
class ListGamesCommand: public Command {

public:
    void execute(string gameName, int socketID);
};

#endif //SERVER_LISTGAMESCOMMAND_H
