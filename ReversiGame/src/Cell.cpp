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

void Cell::setStatus(char newStatus) {
	if (newStatus == WHITE || newStatus == BLACK) {
		cellStat = (Status) newStatus;
	}
}

int Cell::getRow() {
	return row;
}

int Cell::getCol() {
	return col;
}

void Cell::printCell() {
	cout << "(" << row << ", " << col << ")";
}

void Cell::flip() {
  if (cellStat == BLACK) {
    	cellStat = WHITE;
  } else if (cellStat == WHITE) {
    	cellStat = BLACK;
  }
}
