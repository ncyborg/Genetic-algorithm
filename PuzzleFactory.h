#include "SudokuOffspring.cpp.h"

class PuzzleFactory {

	public:	
		virtual Puzzle* createPuzzle(string s) = 0;

};
