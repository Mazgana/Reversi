#ifndef INCLUDE_DISPLAY_H_
#define INCLUDE_DISPLAY_H_

#include <iostream>
#include <limits>
#include <string.h>
#include "Board.h"

using namespace std;

class Display {
public:
	virtual ~Display() {}

	//Output
	virtual void printMessage(string mes) {};

	virtual void printMessageWitheNewLine(string mes) {};

	virtual void printChar(char c) {};

	virtual void printBoard(Board b) {};

	virtual void printCell(Cell c) {};

	virtual void printNewLine() {};

	//Input
	virtual int getInt() const = 0;

	virtual string getString() const = 0;

	virtual char getChar() const = 0;

	//getting one char from the buffer
	virtual void getBufferContent() {};

	//ignoring the next input up to char 'c'
	virtual void ignoreInput(char c) {};

	//clearing the buffer
	virtual void clearBuffer() {};

	//detects whether the value entered fits the value defined in the variable
	virtual bool isInputFailed() const = 0;
};

#endif /* INCLUDE_DISPLAY_H_ */
