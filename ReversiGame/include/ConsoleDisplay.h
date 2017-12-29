#ifndef INCLUDE_CONSOLEDISPLAY_H_
#define INCLUDE_CONSOLEDISPLAY_H_

#include "Display.h"

class ConsoleDisplay : public Display {
public:
	ConsoleDisplay();
	~ConsoleDisplay();

	//Output
	void printMessage(string mes);

	void printMessageWitheNewLine(string mes);

	void printChar(char c);

	void printBoard(Board b);

	void printCell(Cell c);

	void printNewLine();

	//Input
	int getInt() const;

	string getString() const;

	char getChar() const;

	void getBufferContent();

	void ignoreInput(char c);

	void clearBuffer();

	bool isInputFailed() const;
};

#endif /* INCLUDE_CONSOLEDISPLAY_H_ */
