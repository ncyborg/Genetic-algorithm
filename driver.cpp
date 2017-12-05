
#include "GeneticAlgorithm.h";

using namespace std;

int main() {

	int size;
	int max; 

	//take in size
	cout << "Size of each generation: ";
	cin >> size;

	//take in max
	cout << "\nMaximum amount of generations: ";
	cin >> max;

	//run genetic algorithm based on size and max
	GeneticAlgorithm g(size, max);

}
