#ifndef CELL_H_
#define CELL_H_

enum Status {BLACK = 'X', WHITE = 'O', EMPTY = ' '};

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
	void setStatus(Status);

	//Getting the cell's location.
	int getRow();
	int getCol();

	//Print the cell location in the following format: (row, col).
	void printCell();

	void flip();
};


#endif /* CELL_H_ */
