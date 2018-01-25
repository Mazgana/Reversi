#include "Server.h"

pthread_mutex_t mutex_sockets_list;

Server::Server(int port): port(port), serverSocket(0) {
    pool = new ThreadPool(THREADS_NUM);
}

void *handleClient1(void *clientSocket) {
    //calling first function of new thread
    ClientHandler ch;
    long tid = (long)clientSocket;
    ch.handleClient((int)tid);
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

    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);

    createExitThread();

    cout << "waiting for client's connection.." << endl;

    while (true){
        //The first client login
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);

        if (clientSocket == -1)
            throw "Failed to connect the server";

        pthread_mutex_lock(&mutex_sockets_list);
        listOfSockets.push_back(clientSocket);//adding new socket to list
        pthread_mutex_unlock(&mutex_sockets_list);

        Task *tsk = new Task(handleClient1, (void *)clientSocket);
        listOfTasks.push_back(tsk);
        pool->addTask(tsk);
    }
}

void Server::stop(){
    //closing all sockets that were opened
    for (int i = 0; i < (int) listOfSockets.size(); i++) {
        close(listOfSockets[i]);
    }
    listOfSockets.clear();
    for (int i = 0; i < listOfTasks.size(); i++) {
        delete listOfTasks[i];
    }
    pool->terminate();
    close(serverSocket);
    //closing server socket and exiting program
    exit(0);
}

void *exit(void *arg) {
    Server *srvr = (Server *)arg;
    string command;
    //waiting for exit command from console
    while (command.compare("exit")) {
        cin >> command;
    }
    cout << "closing server..." << endl;
    srvr->stop();
}

void Server :: createExitThread() {
    //creating new thread
    pthread_t thread;
    int rc = pthread_create(&thread, NULL, exit, this);
    if (rc == -1) {
        throw "Failed creating thread";
    }
}
