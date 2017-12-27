#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main() {

	ifstream File;
	std::string details;

	File.open("serverConfiguration.txt");
	if (!File) {
		cout << "Error in opening server configuration file." << endl;
		exit(1);
    }

	std::getline(File,details);
	std::size_t pos = details.find("Port: ");
	std::string port = details.substr (pos + 6);
	int portNum = atoi(port.c_str());

	//create server with specified IP and starting it
	Server server(portNum);
	try {
		server.start();
	} catch (const char *msg) {
		cout << "Cannot start server. Reason: " << msg << endl;
		exit(-1);
	}

}

/*
#include <iostream>
#include <pthread.h>
#include <cstdlib>
using namespace std;
#define THREADS_NUM 5

void *printHello(void *threadId) {
    long tid = (long)threadId;
    cout << "Hello world. It's me, thread " << tid << endl;
}

int main() {
    pthread_t threads[THREADS_NUM];
    for (int i = 0; i < THREADS_NUM; i++) {
        cout << "In main: creating thread " << i << endl;
        int rc = pthread_create(&threads[i], NULL, printHello, (void *)i);
        if (rc) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
 */
