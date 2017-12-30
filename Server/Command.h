/*
 * interface command.
 * all command sent out by command manager from server to client/
 */
#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Command {
public:
    // execute given string command with related client and current game list.
    virtual void execute(string gameName, int socketID, map<string, int> &gameList) {};
    //destructor.
    virtual ~Command() {}
};

#endif //SERVER_COMMAND_H
