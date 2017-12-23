#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Command {
public:
    virtual void execute(vector<string> args) = 0;
    virtual ~Command() {}
};


//#include "Command.h"
class PrintCommand: public Command {
public:
    virtual void execute(vector<string> args) {
        for (int i = 0; i < args.size(); i++) {
            cout << args[i] << " ";
        }
        cout << endl;
    }
};

//#include "Command.h"
class StartCommand: public Command {
public:
    virtual void execute(vector<string> args) {
    }
};

//#include "Command.h"
class JoinCommand: public Command {
public:
    virtual void execute(vector<string> args) {
    }
};

//#include "Command.h"
class PlayCommand: public Command {
public:
    virtual void execute(vector<string> args) {
    }
};

//#include "Command.h"
class CloseCommand: public Command {
public:
    virtual void execute(vector<string> args) {
    }
};

#endif //SERVER_COMMAND_H
