#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX_CONNECTED_CLIENTS 2

Server::Server(int port): port(port), serverSocket(0) {
}

void Server::start() {
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


	while (true) {
		struct sockaddr_in firstClientAddress;
		socklen_t firstClientAddressLen = sizeof(firstClientAddress);

		struct sockaddr_in secondClientAddress;
		socklen_t secondClientAddressLen = sizeof(secondClientAddress);

		cout << "waiting for client connections..." << endl;

		//The first client login
		int firstClientSocket = accept(serverSocket, (struct sockaddr *)&firstClientAddress, &firstClientAddressLen);
		cout << "Connected to server" << endl;

		if (firstClientSocket == -1)
			throw "Failed to connect the server";

		cout << "Waiting for other player to join..." << endl;

		//The second client login
		int secondClientSocket = accept(serverSocket, (struct sockaddr *)&secondClientAddress, &secondClientAddressLen);

		cout << "Client connected" << endl;
		if (secondClientSocket == -1)
			throw "The other client failed to connect the server";

		//Sending the clients their login order number
		int firstClient = 1;
		int secondClient = 2;

		int x = write(firstClientSocket, &firstClient, sizeof(firstClient));
		int o = write(secondClientSocket, &secondClient, sizeof(secondClient));

		if (x == -1 || o == -1)
			throw "Error in sending the clients messages.";

		handleClient(firstClientSocket, secondClientSocket);

		close(firstClientSocket);
		close(secondClientSocket);
	}
}

// Handle requests from two clients
void Server::handleClient(int firstClientSocket, int secondClientSocket) {
   int arg1, arg2, n;

   while (true) {
		 // Read new coordinate arguments from player
		 n = read(firstClientSocket, &arg1, sizeof(arg1));
		 cout << n << endl;
		 if (n == -1) {
				 cout << "Error reading arg1" << endl;
				 return;
		 }

		 if (n == 0) {
				cout << "Client disconnected" << endl;
				return;
		 }

		 n = read(firstClientSocket, &arg2, sizeof(arg2));
		 if (n == -1) {
				 cout << "Error reading arg2" << endl;
				 return;
		 }

		 // Write the result coordinates back to the client
		 int w = write(secondClientSocket, &arg1, sizeof(arg1));

		 if (w == -1) {
				cout << "Error writing to socket" << endl;
				return;
		 }

		 int m = write(secondClientSocket, &arg2, sizeof(arg2));
		 if (m == -1) {
				cout << "Error writing to socket" << endl;
				return;
		 }

		 //The end
		 if (arg1 == -3) {
			 return;
		 } else {
			 //swapping the clients
			 int temp = firstClientSocket;
			 firstClientSocket = secondClientSocket;
			 secondClientSocket = temp;
		 }
 	 }
}

void Server::stop() {
   close(serverSocket);
}
