#include "Board.h"
#include <iostream>

Board::Board() {
	length = default_lenth;
	width = default_width;

	int i;
	CellArr.resize(width + 1);
	for (i = 0; i <= width ; i++) {
		CellArr[i].resize(length + 1);
	}
}

Board :: Board(int len, int wid) : length(len), width(wid){
	int i;
	CellArr.resize(width + 1);
	for (i = 0; i <= width ; i++) {
		CellArr[i].resize(length + 1);
	}
}

Board::Board(const Board &b) {
	length = b.length;
	width = b.width;
	CellArr = b.CellArr;
}

void Board :: initialize()
{
	int i, j;
	int x = width/2;
	int y = length/2;

	for (i = 0; i <= length ; i++) {
		for (j = 0; j <= width; j++) {
			Cell cleanCEll(EMPTY, i, j);
			CellArr[i][j] = cleanCEll;
		}
	}

	Cell whiteCell(WHITE, x, y);
	CellArr[x][y] = whiteCell;
	Cell whiteCell2(WHITE, x + 1, y + 1);
	CellArr[x + 1][y + 1] = whiteCell2;
	Cell blackCell(BLACK, x, y + 1);
	CellArr[x][y + 1] = blackCell;
	Cell blackCell2(BLACK, x + 1, y);
	CellArr[x + 1][y] = blackCell2;
}

Status Board ::reveal(int x, int y) const {
	  return CellArr[x][y].getStatus();
}

void Board :: putChip(Status chip, int x, int y) {
    CellArr[x][y].setStatus(chip);
		flipChips(chip, Cell(x,y));
}

void Board :: print() const
{
	int i, j, k;
	for (i = 0; i <= length; i++) {
		for (j = 0; j <= width; j++) {
			if ((i == 0) && (j == 0)){
				cout << "  |";
			} else if ((i == 0) && (j != 0)) {
				cout << " " << j << " |";
			} else if ((j == 0) && (i != 0)) {
				cout << i << " |";
			} else {
				cout << " " << (char) CellArr[i][j].getStatus() << " |";
			}
		}

		cout << "\n";
		for (k = 0; k <= (width); k++) {
			cout << "----";
		}
		cout << "\n";
	}
}

vector<Cell> Board :: getOptions(Status player) {
	vector<Cell> options;

	// loop over board finding valid cells.
    for(int i = 1; i <= length; i++) {
        for (int j = 1; j <= width; j++) {
            if (CellArr[i][j].getStatus() == EMPTY) {
                if (doOneWay(player, i, -1, j, 0, false)) {
                	if (!isCellInOptionArray(CellArr[i][j]))
                    optionalMoves.push_back(CellArr[i][j]);
                }// check North
                if (doOneWay(player, i, 1, j, 0, false)) {
                	if (!isCellInOptionArray(CellArr[i][j]))
                		optionalMoves.push_back(CellArr[i][j]);
                }// check South
                if (doOneWay(player, i, 0, j,-1, false)) {
                	if (!isCellInOptionArray(CellArr[i][j]))
                		optionalMoves.push_back(CellArr[i][j]);
                }// check West
                if (doOneWay(player, i, 0, j, 1, false)) {
                	if (!isCellInOptionArray(CellArr[i][j]))
                		optionalMoves.push_back(CellArr[i][j]);
                }// check East
                if (doOneWay(player, i, -1, j,-1, false)) {
                	if (!isCellInOptionArray(CellArr[i][j]))
                		optionalMoves.push_back(CellArr[i][j]);
                }// check NE
                if (doOneWay(player, i, 1, j, 1, false)) {
                	if (!isCellInOptionArray(CellArr[i][j]))
                		optionalMoves.push_back(CellArr[i][j]);
                }// check SE
                if (doOneWay(player, i, 1, j,-1, false)) {
                	if (!isCellInOptionArray(CellArr[i][j]))
                		optionalMoves.push_back(CellArr[i][j]);
                }// check SW
                if (doOneWay(player, i, -1, j, 1, false)) {
                	if (!isCellInOptionArray(CellArr[i][j]))
                		optionalMoves.push_back(CellArr[i][j]);
                }// check NE
            }
        }
    }
    options = optionalMoves;
    return options;
}


int Board :: doOneWay(Status player, int x, int dx, int y, int dy, bool flip) {
	int chipCounter = 0;
	x = x + dx;
	y = y + dy;
	if (x < 0 || x > length || y < 0 || y > width) {
        return 0;
    }//out of bounds cell
    if (reveal(x,y) == EMPTY || reveal(x,y) == player) {
        return 0;
    }// no continuation in direction
    else {
        while (reveal(x,y) != player && reveal(x,y) != EMPTY) {
            x = x + dx;
            y = y + dy;
            chipCounter++;
            if(x < 0 || x > length || y < 0 || y > width) {
                return 0;
            }// out of bounds
            if(reveal(x,y) == player) {
                if (flip) {
                    x = x - dx;
                    y = y - dy;
                    while (reveal(x, y) != player) {
                        CellArr[x][y].flip();
                        x = x - dx;
                        y = y - dy;
                        if(x < 0 || x > length || y < 0 || y > width) return 0;
                    }
        }//flipping if cell was chosen
        return chipCounter;
            }
        }
    }
    return 0;
}

void Board::flipChips(Status playerColr, Cell chosen) {
    doOneWay(playerColr, chosen.getRow(), -1, chosen.getCol(), 0, true);
    doOneWay(playerColr, chosen.getRow(), 1, chosen.getCol(), 0, true);
    doOneWay(playerColr, chosen.getRow(), -1, chosen.getCol(), 1, true);
    doOneWay(playerColr, chosen.getRow(), 1, chosen.getCol(), 1, true);
    doOneWay(playerColr, chosen.getRow(), 0, chosen.getCol(), 1, true);
    doOneWay(playerColr, chosen.getRow(), -1, chosen.getCol(), -1, true);
    doOneWay(playerColr, chosen.getRow(), 1, chosen.getCol(), -1, true);
    doOneWay(playerColr, chosen.getRow(), 0, chosen.getCol(), -1, true);
}

Status Board::getWinner() const {
    int xCount = 0, oCount = 0;
    for(int i = 0; i <= length; i++) {
        for (int j = 0; j <= width; j++) {
        	  if (CellArr[i][j].getStatus() == BLACK) {
        		  ++xCount;
			  	  	  	}
        	  if (CellArr[i][j].getStatus() == WHITE) {
        	      ++oCount;
			  	  	  	}
				}
    }// going over board and counting
    if (xCount > oCount) {
        return  BLACK;
    }
    else if (xCount < oCount) {
        return  WHITE;
    }
    else {
        return EMPTY;
    }
}

bool Board::isCellInOptionArray(Cell check) {
  int i;

  if ((int)optionalMoves.size() == 0) {
	  return false;
  }

	for (i = 0; i < (int)optionalMoves.size(); i++) {
		if (optionalMoves[i].getRow() == check.getRow() && optionalMoves[i].getCol() == check.getCol())
			return true;
    }

	return false;
}

void Board::cleanOptionalMovesList(){
	optionalMoves.clear();
}

bool Board::isBoardFull() {
	int i, j;
	for (i = 1; i <= length; i++) {
		for (j = 1; j <= width; j++) {
			if (CellArr[i][j].getStatus() == EMPTY) {
				return false;
			}
		}
	}
	return true;
}
