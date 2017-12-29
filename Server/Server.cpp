#include "Server.h"

static vector<int> listOfSockets;
pthread_mutex_t mutex_sockets_list;

Server::Server(int port): port(port), serverSocket(0) {
}


void Server::start() {
      ClientHandler ch;

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

    createExitThread(serverSocket);

    while (true) {
			cout << "waiting for client connections..." << endl;

			//The first client login
			int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
			cout << "Connected to server" << endl;

			if (clientSocket == -1)
				throw "Failed to connect the server";

            pthread_mutex_lock(&mutex_sockets_list);
			listOfSockets.push_back(clientSocket);
            pthread_mutex_unlock(&mutex_sockets_list);

            ch.createNewThread(clientSocket);
		}
}

void Server::stop() {
   close(serverSocket);
}

void *exit(void *serverSocket) {
    string command;
    while (command.compare("exit")) {
        cin >> command;
    }
    cout << "closing server...";
    pthread_mutex_lock(&mutex_sockets_list);
    for (int i = 0; i < (int) listOfSockets.size(); i++) {
        close(listOfSockets[i]);
    }
    pthread_mutex_unlock(&mutex_sockets_list);
    listOfSockets.clear();
    long socket = (long)serverSocket;
    close((int)socket);
}

void Server :: createExitThread(int serverSocket) {
    pthread_t thread;
    int rc = pthread_create(&thread, NULL, exit, (void *)(long)serverSocket);
    if (rc == -1) {
        throw "Failed creating thread";
    }
}