#include "Reproduction.h"

class SudokuOffspring : public Reproduction {

	public:
		Puzzle* makeOffspring(Puzzle* input);
		string getNewData(string old, int input, int index);

	private:
		void printList(vector<int> v);
		void makeInitiateList(vector<int>& myList);
		int getRandomNumFromList(vector<int>& myList);
		void removeNumberFromList(vector<int>& myList, int target);
		bool aMutation();
		void getListOfPossibleNumbers(vector<int>& colListIn, vector<int>& rowListIn, vector<int>& addList);
		void addNumberToList(vector<int>& myList, int target);
		int getSquareListIndex(int randRow, int randCol);
};
