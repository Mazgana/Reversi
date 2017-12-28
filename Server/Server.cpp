#include "Server.h"

Server::Server(int port): port(port), serverSocket(0) {
}


void Server::start() {
      ClientHandler ch;
		vector<int> listOfSockets;

	  serverSocket = socket(AF_INET , SOCK_STREAM , 0);
		if (serverSocket == -1) {
			throw "Error opening socket";
		}

		//Defining the server's settings and binding
		struct sockaddr_in serverAddress;
		bzero((void *)&serverAddress, sizeof(serverAddress));
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_addr.s_addr = INADDR_ANY;
		serverAddress.sin_port = htons(port);

		if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
			throw "Error on binding";
		}

		listen(serverSocket, MAX_CONNECTED_CLIENTS);

	  struct sockaddr_in clientAddress;
	  socklen_t clientAddressLen = sizeof(clientAddress);

	  while (true) {
			cout << "waiting for client connections..." << endl;

			//The first client login
			int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
			cout << "Connected to server" << endl;

			if (clientSocket == -1)
				throw "Failed to connect the server";

			listOfSockets.push_back(clientSocket);
			ch.createNewThread(clientSocket);
		}

	  for (int i = 0; i < (int) listOfSockets.size(); i++) {
		  close(listOfSockets[i]);
		 }
	  listOfSockets.clear();
      stop();
}

void Server::stop() {
   close(serverSocket);
}
