#include "SudokuOffspring.h"
#include "ctime"

Puzzle* SudokuOffspring::makeOffspring(Puzzle* input) {
	//create new clone of input
	//create initiate list
	//create array of vector of rows and colums [9]
	//create array for sqaure in sudoku [9]
	
	//initiate them with the numbers 1 to 9
	//adjust them to represent output

	//MAIN ALGORITHM
	//for (5)
		//get a random row where its not full
		//within that row get a random empty spot

		//if the row isn't full yet
			//get list of possible numbers that could be in this spot [r][c]
			//remove the number form there respective lists
			//update output board
			//update output data

	Sudoku* clone = (Sudoku*)input;
	Sudoku* output = new Sudoku(clone->data);

	vector<int> initiateList;
	makeInitiateList(initiateList);

	vector<int> rowLists[9]; //all numbers that arent in each row
	vector<int> columnLists[9]; //all numbers that arent in each column
	vector<int> squareLists[9]; //all numbers that arent in each square
	vector<int> chooseList[9]; //stores indexes 0 - 9where there is 0

	//fills each vector with numbers 1 to 9
	for (int i = 0; i < 9; i++) {

		rowLists[i] = initiateList;
		columnLists[i] = initiateList;
		squareLists[i] = initiateList;
		chooseList[i] = initiateList;
	}

	//goes through each sqaure in output, if its not empty, remove it fron the row listss/collists and remove index from choose lists
	for (int fr = 0; fr < 9; fr++) {

		for (int fc = 0; fc < 9; fc++) {

			if (output->board[fr][fc].num > 0) {

				removeNumberFromList(rowLists[fr], output->board[fr][fc].num);
				removeNumberFromList(columnLists[fc], output->board[fr][fc].num);
				removeNumberFromList(chooseList[fr], fc);
			}

		}
	}

	//initiates the square list
	//iterates 9 times total
	for (int ir = 0; ir <= 6; ir = ir + 3) {

		for (int ic = 0; ic <= 2; ic++) {

			//determine where on row it should iterate c from
			int tempic = ic * 3;

			//iterates 9 times total in a square
			for (int r = ir; r <= ir + 2; r++) {
				//cycle through the square
				for (int c = tempic; c <= tempic + 2; c++) {
	
					if (output->board[r][c].num > 0){
						//remove from corresponding quadrant
						removeNumberFromList(squareLists[ir+ic], output->board[r][c].num);
					}
				}
			}
		}
	}

	//adds all row indexs that are not empty
	vector<int> validRow; 
	for (int chk = 0; chk < 9; chk++) {
		if (chooseList[chk].size() != 0) {
			validRow.push_back(chk);
		}
	}


	//MAIN ALGORITHM
	for (int i = 0; i < 5; i++) {

		int randRow = validRow.at(rand() % validRow.size());
		int randCol = chooseList[randRow].at(rand() % chooseList[randRow].size()) - 1;

		if (rowLists[randRow].size() > 0) {
			//get common between row list and col list
			vector<int> tempList;
			getListOfPossibleNumbers(columnLists[randCol], rowLists[randRow], tempList);
			
			//get common between temp list and square list
			vector<int> addList;
			int sqIndex = getSquareListIndex(randRow, randCol) - 1;
			getListOfPossibleNumbers(tempList, squareLists[sqIndex], addList);

			int randNum = getRandomNumFromList(addList);
			//removing the number from three lists
			removeNumberFromList(rowLists[randRow], randNum);
			removeNumberFromList(columnLists[randCol], randNum);
			removeNumberFromList(squareLists[sqIndex], randNum);

			//updates output data
			output->board[randRow][randCol].num = randNum;
			output->data = getNewData(output->data, randNum, randRow * 9 + randCol);

		}

	}

	return output;

}

void SudokuOffspring::printList(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i);
	}
	cout << endl;
}

int SudokuOffspring::getSquareListIndex(int r, int c) {
	//determines which quadrant square[r][c] is in
	
	if (r <= 2) {
		if (c <= 2) {
			return 1;
		}
		else if (c <= 5) {
			return 2;
		}
		else {
			return 3;
		}
	}
	else if (r <= 5) {
		if (c <= 2) {
			return 4;
		}
		else if (c <= 5) {
			return 5;
		}
		else {
			return 6;
		}
	}
	else {
		if (c <= 2) {
			return 7;
		}
		else if (c <= 5) {
			return 8;
		}
		else {
			return 9;
		}
	}
}

void SudokuOffspring::addNumberToList(vector<int>& myList, int target) {
	//add to correct spot in myList in order

	//dont add 0
	//for (size of list)
		//if list[i] > target
			//put in spot before list[i]
			//return

	if (target == 0) {return;}

	for (int i = 0; i < myList.size(); i++) {

		if (myList.at(i) > target) {
			myList.insert(myList.begin() + i, target);
			return;
		}

	}

	myList.insert(myList.begin() + myList.size(), target);

}
void SudokuOffspring::getListOfPossibleNumbers(vector<int>& colListIn, vector<int>& rowListIn, vector<int>& addList) {
	//find the similar numbers in both lists
	//add the similar number to a return list
	//return the list

	//while neither collist or row list is empty
		//if they are both the same, valid number that can be put in the spot so
			//push the number to the return list
			//erase both lists fronts
		//else if collists number[0] is bigger than the row lists number[0]
			//erase colList front
		//else 
			//erase rowList front

	vector<int> colList = colListIn; 
	vector<int> rowList = rowListIn; 

	while ( (colList.size() != 0) && (rowList.size() != 0) ) {
		//cout << " col " << colList.at(0) << " [" << colList.size() << "]" << " row " << rowList.at(0) << " [" << rowList.size() << "]" << endl;
		if (colList.at(0) == rowList.at(0)) {

			addList.push_back(colList.at(0));
			colList.erase(colList.begin() + 0);
			rowList.erase(rowList.begin() + 0);

		}else if (colList.at(0) < rowList.at(0)) {

			colList.erase(colList.begin() + 0);

		}else {
			
			rowList.erase(rowList.begin() + 0);

		}

	}

	if (addList.size() == 0) {
		addList.push_back(0);
	}

}

bool SudokuOffspring::aMutation() {
	//decides if should be mutated or not 
	return (rand() % 100) <= 5;

}

int SudokuOffspring::getRandomNumFromList(vector<int>& myList) {
	//gets a random number within the given list
	int r = rand() % myList.size();
	int num = myList.at(r);
	return num;

}

void SudokuOffspring::removeNumberFromList(vector<int>& myList, int target) {
	//removes target from mylist
	//for i to size
		//if mylist(i) == target
			//mylist erase at i 
			//return

	for (int i = 0; i < myList.size(); i++) {

		if (myList.at(i) == target) {

			myList.erase(myList.begin() + i); 
			return;
		}

	}

}

void SudokuOffspring::makeInitiateList(vector<int>& myList) {

	//fill list with numbers 1 to 9
	for (int i = 1; i <= 9; i++) {

		myList.push_back(i);

	}

}

string SudokuOffspring::getNewData(string old, int input, int index) {
	//gets string to index
	//gets index + 1 to end
	//puts input in the middle
	//return

	string first = old.substr(0, index);
	string second = old.substr(index + 1, old.length());
	char c = input + 48;

	string ret = first + c + second;

	return first + c + second;
}
