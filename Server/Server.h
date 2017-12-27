#ifndef SERVER_H_
#define SERVER_H_
/*
 * Server class. creates sockets and connet=cts two clients to read and write coordinates for game.
 */
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
