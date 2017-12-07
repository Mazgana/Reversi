#include "Game.h"

#include <iostream>
using namespace std;

int main() {
	int numOfPlayers = 2;
	bool invalid = true;
	cout << "Choose number of players for this game (1 or 2): " << endl;
	while (invalid) {
		cin >> numOfPlayers;
		if (numOfPlayers != 1 && numOfPlayers != 2 && numOfPlayers != 3) {
			cout << "Please choose 1, 2 or 3 players." << endl;
			cin >> numOfPlayers;
		} else {
			invalid = false;
		}
	}

	Game g(numOfPlayers);
	g.run();
	return 0;
}
