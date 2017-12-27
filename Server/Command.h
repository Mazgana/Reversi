#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H
#include <vector>
#include <string>
#include <iostream>

#include <map>
using namespace std;

class Command {
protected:
    int socket;
public:
    virtual void execute(string gameName, int socketID, map<string, int> &gameList) {};
    virtual ~Command() {}
};

////#include "Command.h"
//class JoinCommand: public Command {
//public:
//    virtual void execute(string gameName, int socketID) {
//
//    }
//};
//
////#include "Command.h"
//class PlayCommand: public Command {
//public:
//    virtual void execute(string gameName, int socketID) {
//    }
//};
//
////#include "Command.h"
//class CloseCommand: public Command {
//public:
//    virtual void execute(string gameName, int socketID) {
//    }
//};

#endif //SERVER_COMMAND_H
