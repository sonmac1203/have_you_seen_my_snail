#ifndef HAVEYOUSEENTHSISNAIL_GARY
#define HAVEYOUSEENTHSISNAIL_GARY

#include <iostream>
#include "Cell.hpp"


enum orientation{up, right, down, left}; // Holding Gary's orientation


class Gary {

private:
	orientation son; 

public:
	unsigned int row, col;

	unsigned int max_row, max_col; // Size of the board

	Gary(unsigned int); // parameterized constructor

	unsigned int get_row(void) { return row; }; // Returns Gary's row

	unsigned int get_col(void) { return col; }; // Return Gary's column

	orientation get_orientation(void) { return son; }; // Return Gary's orientation

	std::string get_word_orientation(void) { // Return Gary's orientation in word
		std::string word;
		if (son == up) {
			word = "up";
		}
		else if (son == right) {
			word = "right";
		}
		else if (son == down) {
			word = "down";
		}
		else {
			word = "left";
		}

		return word;
	}

	void move(Cell* c) { // Move Gary on the board


		// Change Gary's orientation
		if (c->get_color() == 0) { // If the cell is white
			switch (son) {
			case up: son = right;
				break;
			case right: son = down;
				break;
			case down: son = left;
				break;
			case left: son = up;
				break;
			default: son = son;
			}
		}
		else { // If the cell is black
			switch (son) {
			case up: son = left;
				break;
			case right: son = up;
				break;
			case down: son = right;
				break;
			case left: son = down;
				break;
			default: son = son;
			}
		}
		c->change_color(); // Flip the cell's color

		// Move Gary 1 unit forward
		if (son == up) { // If the orientation is up
			if (row == 0) { // If Gary is at the upper edge of the board
				row = max_row - 1;
				col = col;
			}
			else {
				row = row - 1;
				col = col;
			}
		}
		else if (son == right) { // If the orientation is right
			if (col == max_col - 1) { // If Gary is at the right edge of the board
				col = 0;
				row = row;
			}
			else {
				row = row;
				col = col + 1;
			}
		}
		else if (son == down) { // If the orientation is down
			if (row == max_row - 1) { // If Gary is at the lower edge of the board
				row = 0;
				col = col;
			}
			else{
				row = row + 1;
				col = col;
			}
		}
		else { // If the orientation is left
			if (col == 0) { // If Gary is at the left edge of the board
				col = max_col - 1;
				row = row;
			}
			else {
				row = row;
				col = col - 1;
			}

		}
	}

};


Gary::Gary(unsigned int a) { // Parameterized constructor that decides Gary's initial position, at the center, and orientation, up.
	row = (a-1) / 2;
	col = row;

	max_row = a;
	max_col = a;

	son = up;
}


#endif