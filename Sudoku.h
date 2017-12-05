#include "Puzzle.cpp.h"

struct Square {
	int num; 
	bool fixed; 

};

class Sudoku : public Puzzle {

	public:
		Sudoku() {}
		Sudoku(string text);

		void print(ostream& os) const;
		void in(istream& in);
		
		//variables
		Square board[9][9];
		string data = "";
		int fitness = 0; 

	private:

		void fillBoard(string input);
};