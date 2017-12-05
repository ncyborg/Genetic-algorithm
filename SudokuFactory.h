#include "PuzzleFactory.h"

class SudokuFactory : public PuzzleFactory {

	public:

		Puzzle* createPuzzle(string s);

};