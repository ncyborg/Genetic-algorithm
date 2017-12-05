#include "SudokuFactory.h"

Puzzle* SudokuFactory::createPuzzle(string data) {
	
	Sudoku* s = new Sudoku(data);

	return s;

}
