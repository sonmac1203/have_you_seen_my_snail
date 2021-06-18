#include <iostream>
#include <string.h>
#include "Cell.hpp"
#include "Gary.hpp"
#include "Board.hpp"


int main(int argc, char** argv) {
	unsigned int boardSize = atoi(*(argv + 1));
	unsigned int numberSteps = atoi(*(argv + 2));
	std::string outputFilename;
	if (argc == 4) {
		outputFilename = *(argv + 3);
	}

	Board b(boardSize);

	if (argc == 4) {
		b.setOutputFilename(outputFilename);
	}

	b.move_gary(numberSteps);

	return 0;

}