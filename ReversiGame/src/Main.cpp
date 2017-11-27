#include "Game.h"

#include <iostream>
using namespace std;

int main() {
	int numOfPlayers;
	bool invalid = true;
	cout << "Choose the amount of players in this game (1 or 2): " << endl;
	while (invalid) {
		cin >> numOfPlayers;
		if (numOfPlayers != 1 && numOfPlayers != 2) {
			cout << "Please chose 1 or 2 players." << endl;
			cin >> numOfPlayers;
		} else {
			invalid = false;
		}
	}

	Game g(numOfPlayers);
	g.run();
	return 0;
}
