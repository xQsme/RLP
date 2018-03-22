#include "Population.h"

Population::Population(int size) {
	if (size > 0) {
		individuals = (Individual^) malloc(sizeof(Individual)*size);
	}
	populationSize = size;
}

void Population::libertarMemoria()
{
	delete[] individuals;
}

Individual^ Population::getIndividuals() {
	return individuals;
}

int Population::getPopulationSize() {
	return populationSize;
}