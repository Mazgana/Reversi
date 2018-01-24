#include "Server.h"

//#define TASKS_NUM 5

pthread_mutex_t mutex_sockets_list;

Server::Server(int port): port(port), serverSocket(0), running(1) {
    pool = new ThreadPool(THREADS_NUM);
}

void *handleClient1(void *clientSocket) {
    cout << "handling task.." << endl;
    //calling first function of new thread
    ClientHandler ch;
    long tid = (long)clientSocket;
    ch.handleClient((int)tid);
    cout << "after handle" << endl;
}

void Server::start() {
//    ClientHandler ch;

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

    createExitThread(running);

//    Task *tasks[TASKS_NUM];

    cout << "waiting for client's connection.." << endl;

    while (running){

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

        cout << "in loop" << endl;
    }
}

void Server::stop(){

    cout << "closing sockets.." << endl;
    //closing all sockets that were opened
    for (int i = 0; i < (int) listOfSockets.size(); i++) {
        close(listOfSockets[i]);
    }
    listOfSockets.clear();

    cout << "closing tasks.." << endl;

    for (int i = 0; i < listOfTasks.size(); i++) {
        delete listOfTasks[i];
    }
    cout << "terminating pool" << endl;
    pool->terminate();
    cout << "closing server socket.." << endl;
    close(serverSocket);

    pthread_mutex_unlock(&mutex_sockets_list);
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
    //pthread_mutex_lock(&mutex_sockets_list);
}

void Server :: createExitThread(int running) {
    //creating new thread
    pthread_t thread;
    int rc = pthread_create(&thread, NULL, exit, this);
    if (rc == -1) {
        throw "Failed creating thread";
    }
}
