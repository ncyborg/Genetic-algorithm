#include "Sudoku.h"

Sudoku::Sudoku(string text) {

	data = text;
	fillBoard(text);

}

void Sudoku::fillBoard(string input) {
	//get line file
	//for rows
		//for col
			//get num at line 
			//put in square
			//if number > 0
				//set square as fixed
			//set board r/c to square

	int count = 0;

	for (int r = 0; r < 9; r++) {

		for (int c = 0; c < 9; c++) {

			char chr = input.at(count);
			int num = chr - 48;
			Square sq;
			sq.num = num;
			if (num > 0) {
				sq.fixed = true;
			}else {
				sq.fixed = false;
			}
			board[r][c] = sq;
			count++;

		}
	}
}

void Sudoku::print(ostream& os) const{
	//prints board

	for (int r = 0; r < 9; r++) {

		if (r % 3 == 0) {
			cout << "+-------+-------+-------+" << endl;
		}

		int counter = 0;
		for (int c = 0; c < 25; c++) {

			if (c % 8 == 0) {
				cout << "|";
			}
			else if (c % 2 == 1) {
				cout << " ";
			}
			else {

				if (board[r][counter].num != 0) {
					cout << board[r][counter].num;
				}
				else {
					cout << " ";
				}
				counter++;
			}

		}
		cout << endl;

	}
	cout << "+-------+-------+-------+" << endl;

}

void Sudoku::in(istream& in) {
	ifstream myFile("Default.txt");

	string input = "";

	getline(myFile, input);

	data = input;

	fillBoard(input);

}
