#include "Client.h"

Client::Client(const char *serverIP, int serverPort): serverIP(serverIP), serverPort(serverPort), clientSocket(0){
	displayer = new ConsoleDisplay();
}

Client :: ~Client() {
}

void Client::connectToServer() {
    //create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    	}

    //Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw  "Can't parse IP address";
    	}

    // Get a hostest structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    	}

    //Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));

    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    //htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);

    //Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    	}

		displayer->printMessageWitheNewLine("Connected to server");
}

char Client::getOpeningPlayer() {
	try {
        //reading first integer sent from server indicates the player's cheap type.
        int playersPlace = readInt();

        if(playersPlace == 1) {
            displayer->printMessageWitheNewLine("You are the black player X, you go first");
            return 'X';
        } else if (playersPlace == 2) {
            displayer->printMessageWitheNewLine("You are the white player O, you go second");
            return 'O';
        } else {
            displayer->printMessageWitheNewLine("got unreadable starting player from server");
            return ' ';
        }
    } catch  (const char *msg) {
    		return 'F';
    }
}

int Client::receiveCoordinate() {
    //reading an integer from server to be coordinate
    int cor = readInt();
    return cor;
}

void Client::sendMove(int x, int y) {
    //writing to server 2 integers that will be read as coordinates.
	writeInt(x);
	writeInt(y);
}

int Client :: sendCommandMessage(string message) {

	//Sending the server the user's command
	int n =	(int) send(clientSocket, message.c_str(), message.length(), 0);

    if (n == -1) {
        throw "Error writing message to socket.";
   	} else if (n == 0) {
        displayer->printMessageWitheNewLine("The server disconnected.");
       	throw "The server disconnected";
	}

    // reading the server's response if the command succeeded or failed.
	int serverResponse = readInt();
    return serverResponse;
}

void Client::attending() {
	int mes = 1;
	writeInt(mes);
}

vector<string> Client :: receiveStringList(string messageToServer) {
    vector<string> list;
    char line[MAX_STR] = "";
    string gameName;
    int len = 0;

    //Sending the server the user's command
    int n =	(int) send(clientSocket, messageToServer.c_str(), messageToServer.length(), 0);

    if (n == -1) {
        throw "Error writing message to socket.";
    } else if (n == 0) {
        displayer->printMessageWitheNewLine("The server disconnected.");
        throw "The server disconnected";
    }

		// reading the list one name at a time and add them to the games vector
    while (len != -1) { // the list has names
		len = readInt();

    	if (len == -1) //The end of the list
            break;

        int n = recv((int)clientSocket, line, len, 0);
        if (n == -1) {
            throw "Error reading string";
        } else if (n == 0) {
            displayer->printMessageWitheNewLine("The server disconnected.");
            throw "The server disconnected";
        }

        gameName = line;
        list.push_back(gameName);
    }

    return list;
}

int Client::readInt() {
	int val;
	int w = (int) read(clientSocket, &val, sizeof(int));
	if (w == -1) {
		displayer->printMessageWitheNewLine("A connection problem occured.");
		throw "Error reading int";
	} else if (w == 0) {
		displayer->printMessageWitheNewLine("The server disconnected.");
    exit(-1);
	}
	return val;
}

void Client::writeInt(int val) {
	int n = (int) write(clientSocket, &val, sizeof(val));
	if (n == -1) {
		displayer->printMessageWitheNewLine("A connection problem occured.");
		throw "Error writing int";
	} else if (n == 0) {
		displayer->printMessageWitheNewLine("The server disconnected.");
	  exit(-1);
	}
}
