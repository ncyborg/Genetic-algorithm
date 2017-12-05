#include "SudokuFactory.cpp.h"

class Population {

	public:

		virtual void constructFirstGeneration(Sudoku& seed) = 0;
		virtual void addPopulation(Sudoku& Seed) = 0;
		virtual void cull(double percent) = 0;
		virtual void newGeneration() = 0;
		virtual int bestFitness() = 0;
		virtual Sudoku* bestIndividual() = 0; 

		int size;
		vector <Puzzle*> container; 

};
