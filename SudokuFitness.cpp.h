#include "SudokuFitness.h"

int SudokuFitness::howFit(Sudoku myBoard) {
	//calls methods 9 times total
	//for (r = 0 r <= 6 r = r + 3)
		//for (c =0 to 2)
			//total = get conflict rows
			//total = get conflict columns
			//total = get conflicts boxes
			


	int total = 0;

	for (int r = 0; r <= 6; r = r + 3 ) {

		for (int c = 0; c <= 2; c++) {
			total = total + getConflictsRow(myBoard, r + c);
		    total = total + getConflictsColumn(myBoard, r + c);
			total = total + getConflictsBoxes(myBoard, r, c);
		}
	}


	return total;

}

bool SudokuFitness::inList(vector<int> list, int num) {

	for (int i = 0; i < list.size(); i++) {

		if (list.at(i) == num) {
			return true; 
		}

	}

	return false;
}

int SudokuFitness::getConflictsRow(Sudoku myBoard, int r) {
	//bool list used check
	
	//for (int i = 0 to <= 8 i++)
		//get num row[r][i]
		//if list[num]
			//total++
		//else
			//list[num] = true
	//return total

	int total = 0;

	bool usedList[10] = { false, false, false, false, false, false, false, false, false, false };

	for (int i = 0; i <= 8; i++) {
		int num = myBoard.board[r][i].num;
		if (usedList[num]) {
			total++;
		}
		else {
			usedList[num] = true;
		}
	}

	return total; 

}

int SudokuFitness::getConflictsColumn(Sudoku myBoard, int c) {
	//bool list used check

	//for (int i = 0 to <= 8 i++)
		//get num row[r][i]
		//if list[num]
			//total++
		//else
			//list[num] = true
	//return total

	int total = 0;

	bool usedList[10] = { false, false, false, false, false, false, false, false, false, false };

	for (int i = 0; i <= 8; i++) {
		int num = myBoard.board[i][c].num;
		if (usedList[num]) {
			total++;
		}
		else {
			usedList[num] = true;
		}
	}

	return total;
	

}

int SudokuFitness::getConflictsBoxes(Sudoku myBoard, int ir, int ic) {
	//bool list used check

	//for (r to r +2)
		//for (c * 3 to c * 3 + 2
			//get num at board [r][j]
			//if list[num]
				//total++
			//else
				//lsit[num] = true
	//return total

	int total = 0;
	bool usedList[10] = { false, false, false, false, false, false, false, false, false, false };

	ic = ic * 3;

	for (int r = ir; r <= ir + 2; r++) {
		for (int c = ic; c <= ic + 2; c++) {

			int num = myBoard.board[r][c].num;
			
			if (usedList[num]) {
				total++;
			}
			else {
				usedList[num] = true;
			}
		}
	}
	return total; 

}
