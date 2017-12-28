/*
 * Server class. creates sockets and connet=cts two clients to read and write coordinates for game.
 */
#ifndef SERVER_H_
#define SERVER_H_

#include "CommandManager.h"
#include "ClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

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

	void handleClient(int firstClientSocket, int secondClientSocket);

};

#endif /* SERVER_H_ */
