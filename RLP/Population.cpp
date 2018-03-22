#include "Population.h"

Population::Population() {

}

void Population::libertarMemoria()
{
	problem.libertarMemoria();
	for (int i = 0; i < populationSize; i++) {
		delete[] individuals[i];
	}
	delete[] individuals;
}

void Population::setUpPopulation(int populationSize, int seed, std::ifstream& stream) {
	problem.setUpProblem(stream);
	if (populationSize > 0) {
		individuals = (int**)malloc(sizeof(int*)*populationSize);
		if (problem.getTotal() > 0) {
			for (int i = 0; i < populationSize; i++) {
				individuals[i] = (int*)malloc(sizeof(int*)*problem.getTotal());
				srand(seed++);
				for (int j = 0; j < problem.getTotal(); j++) {
					individuals[i][j] = rand() % 2;
				}
			}
		}
	}
	this->populationSize = populationSize;
	this->individualSize = problem.getTotal();
}

int** Population::getIndividuals() {
	return individuals;
}

int Population::getTotal()
{
	return problem.getTotal();
}

int Population::getConnections()
{
	return problem.getConnections();
}

int Population::getPopulationSize() {
	return populationSize;
}

int Population::getIndividualSize() {
	return individualSize;
}

int Population::getFitness() {
	int bestFitness = 9999999999;
	int currentFitness;
	int match;

	for (int i = 0; i < populationSize; i++) {
		currentFitness = 0;
		for (int y = 0; y < problem.getTotal(); y++) {
			match = 0;
			for (int x = 0; x < problem.getTotal(); x++) {
				if (problem.getNodes()[y][x] == 1) {
					if (individuals[i][x] == 1) {
						match++;
						break;
					}
				}
			}
			if (match == 0) {
				currentFitness += 500;
			}
		}
		for (int j = 0; j < individualSize; j++) {
			if (individuals[i][j] == 1) {
				currentFitness += 100;
			}
		}
		if (currentFitness < bestFitness) {
			bestFitness = currentFitness;
		}
	}

	return bestFitness;
}