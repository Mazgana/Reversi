#include "ConsoleDisplay.h"

ConsoleDisplay :: ConsoleDisplay() {
}

void ConsoleDisplay :: printMessage(string message) {
	cout << message;
}

void ConsoleDisplay :: printMessageWitheNewLine(string message) {
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
	cout << "(" << c.getRow() << "," << c.getCol() << ")";
}

void ConsoleDisplay :: printNewLine() {
	cout << endl;
}

int ConsoleDisplay :: getInt() {
	int num;
	cin >> num;

	return num;
}

string ConsoleDisplay :: getString() {
	string inputStr;
	cin >> inputStr;

	return inputStr;
}

void ConsoleDisplay :: getBufferContent() {
	cin.get();
}

void ConsoleDisplay :: ignoreInput(char c) {
    cin.ignore(numeric_limits<streamsize>::max(), c);
}

void ConsoleDisplay :: clearBuffer() {
	cin.clear();
}

bool ConsoleDisplay :: isInputFailed() {
	return cin.fail();
}
