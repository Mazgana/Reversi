#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Command {
protected:
    vector<string> gamesList;
    int socket;
public:
    virtual void execute(vector<string> args) = 0;
    virtual ~Command() {}
};

class StartCommand: public Command {

public:
    StartCommand(vector<string> &list){
        gamesList = list;
//        socket = sock;
    }
    void execute(vector<string> args) {
        cout << "started command" << endl;
        string &add = args.front();
        gamesList.push_back(add);
    }
};

//#include "Command.h"
class ListGamesCommand: public Command {
public:
    void execute(vector<string> args) {

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
