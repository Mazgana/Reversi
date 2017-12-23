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
