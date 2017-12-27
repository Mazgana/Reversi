//
// Created by leah on 27/12/17.
//

#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H

#include "Command.h"

class StartCommand: public Command {

public:
    StartCommand();
    void execute(vector<string> args);
};

#endif //SERVER_STARTCOMMAND_H
