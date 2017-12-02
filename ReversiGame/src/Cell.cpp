#include "Cell.h"
#include <iostream>

using namespace std;

Cell::Cell() {
	cellStat = EMPTY;
	row = 0;
	col = 0;
}

Cell::Cell(Status currentStatus, int currentRow, int currentCol) {
	cellStat = currentStatus;
	row = currentRow;
	col = currentCol;
}

Cell::Cell(int currentRow, int currentCol) {
	cellStat = EMPTY;
	row = currentRow;
	col = currentCol;
}

Status Cell::getStatus() const {
	return cellStat;
}

void Cell::setStatus(Status newStatus) {
		cellStat = newStatus;
}

int Cell::getRow() const {
	return row;
}

int Cell::getCol() const {
	return col;
}

void Cell::printCell() const {
	cout << "(" << row << ", " << col << ")";
}

void Cell::flip() {
  if (cellStat == BLACK) {
    	cellStat = WHITE;
  } else if (cellStat == WHITE) {
    	cellStat = BLACK;
  }
}
