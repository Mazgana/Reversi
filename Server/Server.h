#ifndef SERVER_H_
#define SERVER_H_

class Server {
public:
	Server(int port);
	void start();
	void stop();

private:
	int port;
	int serverSocket;

	void handleClient(int clientSocket, int secondClientSocket);
};

#endif /* SERVER_H_ */
