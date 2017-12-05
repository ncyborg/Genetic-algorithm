
#include "SudokuPopulation.cpp.h"

class GeneticAlgorithm {
	public:

		GeneticAlgorithm(int genSize, int genMax) {

			//create first sudoku from file

			//fill population with first sudoku to (size)

			//for(# of generations)
				//cull x percent of the generation
				//breed 10 per each one thats left

			//print best sudoku puzzle

			srand(time(NULL));

			Sudoku sud;

			cin >> sud;
			cout << sud << endl;

			SudokuPopulation pop(sud, genSize);
			SudokuFitness f;

			double cullPercent = .9;

			Sudoku bestAll = sud;
			int bestAllFit = 216;

			for (int i = 1; i <= genMax; i++) {
				cout << "Culling gen " << i << " - Best[";
				pop.cull(cullPercent);

				Sudoku* best = pop.bestIndividual();
				cout << best->fitness;

				//best is 0
				if (best->fitness == 0) {
					i = genMax; // end the for loop
				}

				cout << "] - Breding gen " << i << endl;
				pop.newGeneration();
				

				//saving best of all time
				if (best->fitness < bestAllFit) {
					bestAll = *best;
					bestAllFit = best->fitness;
				}

			}
	
			cout << "\nBest in last gen" << endl;
			Sudoku* best = pop.bestIndividual();
			cout << *best << endl;
			cout << "Fitness: " << best->fitness << endl;
			cout << endl;
			cout << "\nBest all time" << endl;
			cout << bestAll << endl;
			cout << "Fitness: " << bestAllFit << endl;

			int pause = 0;
			cin >> pause;
		}

}
;