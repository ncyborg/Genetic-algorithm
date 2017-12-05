#include "Population.h"

class SudokuPopulation : public Population {

	friend ostream& operator<< (ostream& o, const SudokuPopulation& p);

	public:

		SudokuPopulation(Sudoku& seed, int s);
		~SudokuPopulation();

		void initializeContainerFitness();
		void constructFirstGeneration(Sudoku& seed);
		void addPopulation(Sudoku& Seed);
		void cull(double percent);
		int getBestIndex();
		void newGeneration();
		int bestFitness();
		Sudoku* bestIndividual();

};