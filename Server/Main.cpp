#include "Server.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	//create server with specified IP and starting it
	Server server(5000);
	try {
		server.start();
	} catch (const char *msg) {
		cout << "Cannot start server. Reason: " << msg << endl;
		exit(-1);
	}
}
