#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main() {

	ifstream File;
	string details;

	//opening file configuration for given port
	File.open("serverConfiguration.txt");
	if (!File) {
		cout << "Error in opening server configuration file." << endl;
		exit(1);
    }

	//reading info from file to number of port
	getline(File,details);
	size_t pos = details.find("Port: ");
	string port = details.substr (pos + 6);
	int portNum = atoi(port.c_str());

	//create server with specified IP and starting it
	Server server(portNum);
	try {
		server.start();
		server.stop();
	} catch (const char *msg) {
		cout << "Cannot start server. Reason: " << msg << endl;
		exit(-1);
	}
}
