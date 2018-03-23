#include "Population.h"
#define SELECTION_PERCENTAGE 0.2

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
				srand(seed+=100);
				for (int j = 0; j < problem.getTotal(); j++) {
					individuals[i][j] = rand() % 2;
				}
			}
		}
	}
	this->populationSize = populationSize;
	this->individualSize = problem.getTotal();
}

void Population::calculateFitness() {

	int total = SELECTION_PERCENTAGE * populationSize;
	free(topPercent);
	topPercent = (int*)malloc(sizeof(int)*total);
	int* fitnesses = (int*)malloc(sizeof(int)*populationSize);
	int* indexes = (int*)malloc(sizeof(int)*populationSize);

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
		fitnesses[i] = currentFitness;
		indexes[i] = i;
	}

	for (int i = 0; i < populationSize; i++)
	{
		for (int j = 0; j < populationSize - 1; j++)
		{
			if (fitnesses[j] > fitnesses[j + 1])
			{
				int temp = fitnesses[j];
				int tempIndex = indexes[j];
				fitnesses[j] = fitnesses[j + 1];
				fitnesses[j + 1] = temp;
				indexes[j] = indexes[j + 1];
				indexes[j + 1] = tempIndex;
			}
		}
	}

	fitness = fitnesses[0];
	disconnected = 0;
	regenerators = 0;
	for (int y = 0; y < problem.getTotal(); y++) {
		match = 0;
		for (int x = 0; x < problem.getTotal(); x++) {
			if (problem.getNodes()[y][x] == 1) {
				if (individuals[indexes[0]][x] == 1) {
					match++;
					break;
				}
			}
		}
		if (match == 0) {
			disconnected++;
		}
	}
	for (int j = 0; j < individualSize; j++) {
		if (individuals[indexes[0]][j] == 1) {
			regenerators++;
		}
	}

	for (int i = 0; i < total; i++) {
		topPercent[i] = indexes[i];
	}

	delete[] fitnesses;
	delete[] indexes;
}

int** Population::getIndividuals() {
	return individuals;
}

int* Population::getTopPercent() {
	return topPercent;
}

int Population::getFitness() {
	return fitness;
}

int Population::getDisconnected() {
	return disconnected;
}
int Population::getRegenerators() {
	return regenerators;
}

int Population::getPopulationSize() {
	return populationSize;
}

int Population::getIndividualSize() {
	return individualSize;
}

int Population::getTotal()
{
	return problem.getTotal();
}

int Population::getConnections()
{
	return problem.getConnections();
}