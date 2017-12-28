#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H

#include <unistd.h>
#include "Command.h"

class JoinCommand: public Command {

public:
    JoinCommand();

    void execute(string gameName, int socketID, map<string, int> &gameList);

    void playGame(int firstClientSocket, int secondClientSocket);
};


#endif //SERVER_JOINCOMMAND_H
