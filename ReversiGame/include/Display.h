#ifndef INCLUDE_DISPLAY_H_
#define INCLUDE_DISPLAY_H_

#include <iostream>
#include <string.h>
#include "Board.h"

using namespace std;

class Display {
public:
	virtual void printMessage(std::string mes) {};

	virtual void printMessageWitheNewLine(std::string mes) {};

	virtual void printChar(char c) {};

	virtual void printBoard(Board b) {};

	virtual void printCell(Cell c) {};

	virtual void printNewLine() {};
};

#endif /* INCLUDE_DISPLAY_H_ */
