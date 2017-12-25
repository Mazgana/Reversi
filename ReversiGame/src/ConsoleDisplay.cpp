#include "ConsoleDisplay.h"

ConsoleDisplay :: ConsoleDisplay() {
}

void ConsoleDisplay :: printMessage(std::string message) {
	cout << message;
}

void ConsoleDisplay :: printMessageWitheNewLine(std::string message) {
	cout << message << endl;
}

void ConsoleDisplay :: printChar(char c) {
	cout << c;
}

void ConsoleDisplay :: printBoard(Board b) {
	int i, j, k;
	for (i = 0; i <= b.getLength(); i++) {//printing board in given format
		for (j = 0; j <= b.getWidth(); j++) {
			if ((i == 0) && (j == 0)){
				cout << "  |";
			} else if ((i == 0) && (j != 0)) {
				cout << " " << j << " |";
			} else if ((j == 0) && (i != 0)) {
				cout << i << " |";
			} else {
				cout << " " << (char)b.getSpecificCell(i, j).getStatus() << " |";
			}
		}

		cout << "\n";
		for (k = 0; k <= (b.getWidth()); k++) {
			cout << "----";
		}
		cout << "\n";
	}
}

void ConsoleDisplay :: printCell(Cell c) {
	cout << "(" << c.getRow() << ", " << c.getCol() << ")";
}

void ConsoleDisplay :: printNewLine() {
	cout << endl;
}
