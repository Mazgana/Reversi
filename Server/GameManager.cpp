#include "GameManager.h"

void GameManager::playGame(int firstClientSocket, int secondClientSocket) {
    int arg1, arg2, n, dumb;
    int disconnection = -4;

    while (true) {
        // Read new coordinate arguments from player
        n = read(firstClientSocket, &arg1, sizeof(arg1));
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

        n = read(firstClientSocket, &arg2, sizeof(arg2));
        if (n == -1) {
            cout << "Error reading arg2" << endl;
            return;
        }

        // Write the result coordinates back to the client
        int w = write(secondClientSocket, &arg1, sizeof(arg1));

        if (w == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }

        int check = read(secondClientSocket, &dumb, sizeof(dumb));

        if (check == 0) {
            write(firstClientSocket, &disconnection, sizeof(disconnection));
            cout << "Client 2 disconnected" << endl;
            return;
        }

        int m = write(secondClientSocket, &arg2, sizeof(arg2));
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