#ifndef CELL_H_
#define CELL_H_

#include <iostream>

enum Status {BLACK = 'X', WHITE = 'O', EMPTY = ' '};
/*
 * Cell class. holds coordinate and changes chip according to game.
 */
class Cell {
private:
	Status cellStat;
	int row;
	int col;

public:
	Cell();
	Cell(Status, int, int);
	Cell(int, int);

	//Getting the cell's status.
	Status getStatus() const;

	//Set the cell's status to the given status.
	void setStatus(Status newStatus);

	//Getting the cell's location.
	int getRow() const;
	int getCol() const;

	//flipping chip- changing status from black to white or vice versa
	void flip();
};

#endif /* CELL_H_ */
