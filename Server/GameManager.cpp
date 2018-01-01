#include "GameManager.h"

void GameManager::playGame(int firstClientSocket, int secondClientSocket) {
    int arg1, arg2, n, dumb;
    int disconnection = -4;

    sendChips(firstClientSocket, secondClientSocket);

    while (true) {
        // Read new coordinate arguments from player
        n = (int) read(firstClientSocket, &arg1, sizeof(arg1));
        if (n == -1) {
            cout << "Error reading arg1" << endl;
            return;
        }

        if (arg1 == -3)
            return;

        if (n == 0) {
            write(secondClientSocket, &disconnection, sizeof(disconnection));
            cout << "Client 1 disconnected" << endl;
            return;
        }

        n = (int) read(firstClientSocket, &arg2, sizeof(arg2));
        if (n == -1) {
            cout << "Error reading arg2" << endl;
            return;
        }

        // Write the result coordinates back to the client
        int w = (int) write(secondClientSocket, &arg1, sizeof(arg1));

        if (w == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }

        int check = (int) read(secondClientSocket, &dumb, sizeof(dumb));

        if (check == 0) {
            write(firstClientSocket, &disconnection, sizeof(disconnection));
            cout << "Client 2 disconnected" << endl;
            return;
        }

        int m = (int) write(secondClientSocket, &arg2, sizeof(arg2));
        if (m == -1) { //Client disconnected
            write(firstClientSocket, &disconnection, sizeof(disconnection));
            return;
        }

        //swapping the clients
        int temp = firstClientSocket;
        firstClientSocket = secondClientSocket;
        secondClientSocket = temp;
    }
}

void GameManager:: sendChips(int firstClientSocket, int secondClientSocket) {
    int firstClient = 1;
    int secondClient = 2;

    //sending black chip to first client and white to second
    int x = (int) write(firstClientSocket, &firstClient, sizeof(firstClient));
    int o = (int) write(secondClientSocket, &secondClient, sizeof(secondClient));

    if (x == -1 || o == -1)
        throw "Error in sending the clients messages.";

}