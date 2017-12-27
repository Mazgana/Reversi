
#include "CommandManager.h"
#include "ClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>

#define MAX_STR 12

ClientHandler::ClientHandler(){}

void ClientHandler :: handleClient (int firstClientSocket) {
    int n;
    char buffer[MAX_STR];
    vector<string> args;
//    args.emplace_back("lord");
    long firstClient = (long)firstClientSocket;
    /*n = read((int)firstClient, &buffer, sizeof(buffer));
    if (n == -1) {
        cout << "Error reading choice" << endl;
    }*/
    string choice = "start";
    CM.executeCommand(choice, args);
/*    pthread_t thread;
    cout << "creating thread..." << endl;
    threads.push_back(thread);
    int rc = pthread_create(&thread, NULL, getChoice, (void *) firstClientSocket);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }
    pthread_exit(NULL);
*/
 }


void ClientHandler :: getChoice (void *firstClientSocket) {
    int n;
    char buffer[MAX_STR];
    vector<string> args;
//    args.emplace_back("lord");
    long firstClient = (long)firstClientSocket;
    n = read((int)firstClient, &buffer, sizeof(buffer));
    if (n == -1) {
        cout << "Error reading choice" << endl;
    }
    string choice = "start";
    CM.executeCommand(choice, args);
}
