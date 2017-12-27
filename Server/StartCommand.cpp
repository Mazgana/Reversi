#include <unistd.h>
#include <sys/socket.h>
#include "StartCommand.h"

StartCommand::StartCommand() {

}

void StartCommand::execute(string gameName, int socketID) {
    string name = gameName;
    while(GameList.count(name)) {
        int fail = -1;
        int w = write(socketID, &fail, sizeof(fail));
        if (w == -1) {
            cout << "Error writing to socket" << endl;
            return;
				}

				char buffer[MAX_STR];
				int n = recv(socketID, buffer, MAX_STR, 0);
				if (n == -1) {
					cout << "Error reading choice" << endl;
				}
				name = buffer;
			}

    GameList[name] = socketID;
    int success = 1;
    int m = write(socketID, &success, sizeof(success));
    if (m == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
}
