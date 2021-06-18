#ifndef HAVEYOUSEENTHSISNAIL_CELL
#define HAVEYOUSEENTHSISNAIL_CELL

#include <string>

// Declare an enumaration data type to store the Cell's color
enum CellColor { white, black };

// Declare the Cell Class
class Cell {
public:
	// Declare default constructor to initialize color to white
	Cell();

	// Declare member function getter for the color (get_color). Returns CellColor
	CellColor get_color (void) { return color; };
	
	// Declare a member to flip the color (change_color)
	void change_color() {
		if (color == white) {
			color = black;
		}
		else {
			color = white;
		}
	}

	// Declare a member to print the string for this color.
	// white = "0", black = "1"

	std::string get_color_string() {
		std::string hihi;
		if (color == white) {
			hihi = "0";
		}
		else {
			hihi = "1";
		}
		return hihi;
	}

private:
	// Declare the color of this cell (color) as type CellColor
	CellColor color;

};

Cell::Cell() {
	color = white;
}

#endif
