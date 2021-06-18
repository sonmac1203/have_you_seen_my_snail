#ifndef HAVEYOUSEENTHSISNAIL_BOARD
#define HAVEYOUSEENTHSISNAIL_BOARD

#include "Cell.hpp"
#include "Gary.hpp"


#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

class Board {

public:

	unsigned int board_size;

	Board(unsigned int); // Parameterized constructor

	std::string file_name;
	void setOutputFilename(std::string name) { // Assign the file's name
		file_name = name;
	}

	void move_gary(unsigned int steps) { // A function that moves Gary

		// Create the board which is a vector of vectors of Cell
		std::vector< std::vector<Cell>> cellArr;
		cellArr.resize(board_size);
		for (int i = 0; i < cellArr.size(); i++) {
			cellArr.at(i).resize(board_size);
		} // Automatically allocate memory's for the vector using .resize()

		for (int i = 0; i < cellArr.size(); i++) { // Assign the Cell class to each of the element of the array
			std::vector<Cell>* current_Row = &cellArr.at(i);
			for (int j = 0; j < cellArr.at(i).size(); j++) {
				Cell* current_Cell = &cellArr.at(i).at(j);
			}
		}


		Gary the_snail(board_size); // Declare a variable of type Gary
		Cell cur_cell; // Declare a variable of type Cell


		if (!file_name.empty()) { // If the file's name is PROVIDED 
			std::ofstream print(file_name, std::ofstream::out); // Open the file for writing

			// Print out the initial state
			print << "[Gary Location] {" << the_snail.get_row() << ", " << the_snail.get_col() << "} [Gary Orientation] " << the_snail.get_word_orientation() << " ";
			for (int s = 0; s < cellArr.size(); s++) {
				print << "[Row " << s << "] ";
				for (int t = 0; t < cellArr.at(s).size(); t++) {
					Cell* current_Cell = &cellArr.at(s).at(t);
					print << current_Cell->get_color_string() << " ";
				}
			}
			print << std::endl; // For formatting

			// Print out the desired executions
			for (int i = 0; i < steps; i++) {

				the_snail.move(&cellArr.at(the_snail.get_row()).at(the_snail.get_col())); // Call the function move from class Gary to move Gary

				print << "[Gary Location] {" << the_snail.get_row() << ", " << the_snail.get_col() << "} [Gary Orientation] " << the_snail.get_word_orientation() << " ";
				for (int s = 0; s < cellArr.size(); s++) { // Print out the vector of vectors
					print << "[Row " << s << "] ";
					for (int t = 0; t < cellArr.at(s).size(); t++) {
						Cell* current_Cell = &cellArr.at(s).at(t);
						print << current_Cell->get_color_string() << " ";
					}
				}
				print << std::endl; // For formatting
			}
			print.close(); // Close the output file
		}

		else{ // If the file's name is NOT PROVIDED

			// Print out the initial state
			std::cout << "[Gary Location] {" << the_snail.get_row() << ", " << the_snail.get_col() << "} [Gary Orientation] " << the_snail.get_word_orientation() << " ";
			for (int s = 0; s < cellArr.size(); s++) {
				std::cout << "[Row " << s << "] ";
				for (int t = 0; t < cellArr.at(s).size(); t++) {
					Cell* current_Cell = &cellArr.at(s).at(t);
					std::cout << current_Cell->get_color_string() << " ";
				}
			}
			std::cout << std::endl; // For formatting

			// Print out the desired executions
			for (int i = 0; i < steps; i++) {

				the_snail.move(&cellArr.at(the_snail.get_row()).at(the_snail.get_col())); // Call the function move from class Gary to move Gary

				std::cout << "[Gary Location] {" << the_snail.get_row() << ", " << the_snail.get_col() << "} [Gary Orientation] " << the_snail.get_word_orientation() << " ";
				for (int s = 0; s < cellArr.size(); s++) { // Print out the vector of vectors
					std::cout << "[Row " << s << "] ";
					for (int t = 0; t < cellArr.at(s).size(); t++) {
						Cell* current_Cell = &cellArr.at(s).at(t);
						std::cout << current_Cell->get_color_string() << " ";
					}
				}
				std::cout << std::endl; // For formatting
			}
		}
	}
};


Board::Board(unsigned int N) { // Parameterized constructor that decides the valid size for the board
	if (N % 2 == 0) {
		std::cout << "Board dimension must be an odd number!! Got " << N << " and adding 1 to equal " << N + 1 << std::endl;
		N = N + 1;
	}
	Board::board_size = N;
}

#endif