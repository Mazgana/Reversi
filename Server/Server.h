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

using namespace std;

#define MAX_CONNECTED_CLIENTS 2

class Server {
public:
	//constructor.
	Server(int port);
	//starting connection
	void start();
	//ending connection
	void stop();

private:
	int port;
	int serverSocket;
	//gets ID of server socket and creates new thread to wait for an exit from console.
    void createExitThread(int serverSocket);
};

#endif /* SERVER_H_ */
