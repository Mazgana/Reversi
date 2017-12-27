#ifndef INCLUDE_DISPLAY_H_
#define INCLUDE_DISPLAY_H_

#include <iostream>
#include <limits>
#include <string.h>
#include "Board.h"

using namespace std;

class Display {
public:
	//Output
	virtual void printMessage(string mes) {};

	virtual void printMessageWitheNewLine(string mes) {};

	virtual void printChar(char c) {};

	virtual void printBoard(Board b) {};

	virtual void printCell(Cell c) {};

	virtual void printNewLine() {};

	//Input
	virtual int getInt() {};

	virtual string getString() {};

	virtual void getBufferContent() {};

	virtual void ignoreInput(char c) {};

	virtual void clearBuffer() {};

	virtual bool isInputFailed() {};
};

#endif /* INCLUDE_DISPLAY_H_ */
