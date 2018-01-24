/*
 * Server class. creates sockets and connet=cts two clients to read and write coordinates for game.
 */
#ifndef SERVER_H_
#define SERVER_H_

#include "CommandManager.h"
#include "ClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include "Task.h"
#include "ThreadPool.h"

#define THREADS_NUM 1
#define MAX_CONNECTED_CLIENTS 20
using namespace std;

class Server {
public:
	//constructor.
	Server(int port);
	//starting connection
	void start();
	//ending connection
    void stop();

private:
    int running;
	int port;
	int serverSocket;
    vector<int> listOfSockets;
    vector<Task *> listOfTasks;
    ThreadPool *pool;
	//gets ID of server socket and creates new thread to wait for an exit from console.
    void createExitThread(int running);
};

#endif /* SERVER_H_ */
