#ifndef INCLUDE_CONSOLEDISPLAY_H_
#define INCLUDE_CONSOLEDISPLAY_H_

#include "Display.h"

class ConsoleDisplay : public Display {
public:
	ConsoleDisplay();

	void printMessage(std::string mes);

	void printMessageWitheNewLine(std::string mes);

	void printChar(char c);

	void printBoard(Board b);

	void printCell(Cell c);

	void printNewLine();
};


#endif /* INCLUDE_CONSOLEDISPLAY_H_ */
