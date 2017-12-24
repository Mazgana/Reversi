#include "TwoClientsGame.h"
#include "AiGame.h"
#include "RemoteGame.h"

#include <iostream>
using namespace std;

int main() {
	int gameType = 0;
	bool invalid = true;
	//opening message for reversi game.
	cout << "Welcome to Reversi!" << endl << endl;
	cout << "Choose an opponent type: " << endl << "1. a human local player" << endl
		 << "2. an AI player" << endl << "3. a remote player" <<endl;
	while (invalid) {//validating users game choice.
		cin >> gameType;
		if (gameType != 1 && gameType != 2 && gameType != 3) {
			cout << "Invalid input. Please enter 1, 2 or 3." << endl;
			cin >> gameType;
		} else {
			invalid = false;
		}
	}
	//creating and running chosen game

	if (gameType == 1) {
		TwoClientsGame clients;
		clients.run();
	} else if (gameType == 2) {
		AiGame computer;
		computer.run();
	} else {
		RemoteGame remote;
		remote.run();
	}
	return 0;
}
