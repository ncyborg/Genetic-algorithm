#include "SudokuPopulation.h"

SudokuPopulation::SudokuPopulation(Sudoku& seed, int s) {
	size = s;
	constructFirstGeneration(seed);
}
SudokuPopulation::~SudokuPopulation() {
	//for size in containter
		//delte each puzzle

	for (int i = 0; i < container.size(); i++) {

		Puzzle* in = container.at(i);
		Sudoku* p = (Sudoku*)in;
		delete p;

	}
}

void SudokuPopulation::cull(double percent) {
	//put top x number of best in container
	//delete others

	//get number that should be left in list
	//for number that should be left
		//get the best in list
		//add it to temp container
		//remove it from old container

	//delete all thats left in old container
	//set old to temp

	vector<Puzzle*> n;

	initializeContainerFitness();

	int fitNum = size - ((int)size * percent);

	for (int i = 0; i < fitNum; i++) {

		Sudoku* best = bestIndividual();
		n.push_back(best);
		int index = getBestIndex();
		container.erase(container.begin() + index);

	}

	for (int d = 0; d < container.size(); d++) {

		Puzzle* p = container.at(d);
		Sudoku* s = (Sudoku*)p;
		delete s;
	}

	container = n;

}

void SudokuPopulation::newGeneration() {

	//for number in container
		//get at i
		//reproduce 10 of at i 
		//put in container
	//calculate their finesses

	vector<Puzzle*> temp = container;
	container.clear();
	for (int i = 0; i < temp.size(); i++) {
		Puzzle* p = temp.at(i);
		Sudoku* s = (Sudoku*)p;

		addPopulation(*s);

	}

	initializeContainerFitness();

}


void SudokuPopulation::constructFirstGeneration(Sudoku& seed) {

	//creates first population of all new sudoku puzzles

	for (int i = 0; i < size; i++) {
		
		SudokuFactory f;
		Puzzle* in = f.createPuzzle(seed.data);
		Sudoku* p = (Sudoku*) in;
		container.push_back(p);

	}

}

void SudokuPopulation::addPopulation(Sudoku& seed) {
	//get seed
	//add seed to container

	//for (size(9))
		//if a mutant
			//get mutant baby
		//else
			//get regular baby
	//add baby to list


	//cout << seed.data << endl;
	//cout << "pass" << endl;
	
	for (int i = 0; i < 10; i++) {
		
		Puzzle* p;

		if ((rand() % size) <= 5) {
			SudokuOffspring parent; 
			p = parent.makeOffspring(&seed);
		}else {
			SudokuFactory f;
			p = f.createPuzzle(seed.data);
		}

		Sudoku* s = (Sudoku*) p;
		
 		container.push_back(s);

	}

}

void SudokuPopulation::initializeContainerFitness() {
	//caculate all sudoku fitness all sudokus fitness
	SudokuFitness f;

	for (int i = 0; i < container.size(); i++) {

		Puzzle* p = container.at(i);
		Sudoku* s = (Sudoku*)p;

		s->fitness = f.howFit(*s);

	}

}

int SudokuPopulation::getBestIndex() {

	//returns index of best sudoku in container
	
	int best = 0;
	int index = 0;

	for (int i = 0; i < container.size(); i++) {
		
		Puzzle* p = container.at(i);
		Sudoku* s = (Sudoku*) p;

		int fitNum = s->fitness;

		if (fitNum < best) {
			best = fitNum;
			index = i;
		}

	}
	//cout << best << " " << index << endl;
	return index;
}

int SudokuPopulation::bestFitness() {
	SudokuFitness f;
	return f.howFit(*((Sudoku*) &container.at(getBestIndex())));

}
Sudoku* SudokuPopulation::bestIndividual() {
	SudokuFitness f;

	Puzzle* p = container.at(getBestIndex());
	Sudoku* s = (Sudoku*) p;

	return s;

}

ostream& operator<< (ostream& o, const SudokuPopulation& p) {

	cout << "Population" << endl;

	for (int i = 0; i < p.container.size(); i++) {
		Puzzle* out = p.container.at(i);
		Sudoku* s = (Sudoku*) out; 
		cout << *s << endl;

	}

	return o;
}
