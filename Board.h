#ifndef BOARD_H_
#define BOARD_H_

#include "Cell.h"
#include <vector>
using namespace std;

class Board {
	private:
		int length;
		int width;
		vector<vector<Cell> > CellArr;

	public:
		Board();
		Board(int, int);
		Board(const Board &b);

    //initializing game board with four pieces in middle of board.
    void initialize();

    //returns piece currently on specific board cell.
    Status reveal(int x, int y) const;

    //prints cell content to console.
    void print() const;

    //returns list of optional cell according to reversi game logic.
    vector <Cell> getOptions(char player);

    //put a chip on a specific cell.
    void putChip(Status chip, int x, int y);

    //checks if a specific direction foloows game logic to make cell valid for turn.
    int doOneWay(char player, int x, int dx, int y, int dy, bool flip);

    //flips all the chips from specific cell in every optional direction for the current player.
    void flipChips(Status playerColr, Cell chosen);

    //check score and counts chips. returns the chip with highest score.
    char getWinner() const;

		//Checking if the current board has no more empty cells.
		bool isBoardFull();
};

#endif /* BOARD_H_ */
