#ifndef INCLUDE_CONSOLEDISPLAY_H_
#define INCLUDE_CONSOLEDISPLAY_H_

#include "Display.h"

class ConsoleDisplay : public Display {
public:
	ConsoleDisplay();

	//Output
	void printMessage(string mes);

	void printMessageWitheNewLine(string mes);

	void printChar(char c);

	void printBoard(Board b);

	void printCell(Cell c);

	void printNewLine();

	//Input
	int getInt();

	string getString();

	char getChar();

	void getBufferContent();

	void ignoreInput(char c);

	void clearBuffer();

	bool isInputFailed();
};

#endif /* INCLUDE_CONSOLEDISPLAY_H_ */
