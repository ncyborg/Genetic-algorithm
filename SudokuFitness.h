#include "Fitness.h"


class SudokuFitness : public Fitness {

	public:

		int howFit(Sudoku myBoard);
	private:
		int getConflictsRow(Sudoku myBoard, int r);

		int getConflictsColumn(Sudoku myBoard, int c);

		int getConflictsBoxes(Sudoku myBoard, int r, int c);

		bool inList(vector<int> list, int num);
};

