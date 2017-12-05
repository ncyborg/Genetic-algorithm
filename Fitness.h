#include "Sudoku.cpp.h"

class Fitness {
	public: 
		virtual int howFit(Sudoku myBoard) { return 0; }
};
