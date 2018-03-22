#pragma once
#include <sstream>
#include "Problem.h"
using namespace std;
ref class Population
{
public:
	Population();
	void libertarMemoria();
	void setUpPopulation(int populationSize, int seed, std::ifstream& stream);
	int** getIndividuals();
	int getPopulationSize();
	int getIndividualSize();
	int getFitness();
	int getTotal();
	int getConnections();
private:
	Problem problem;
	int** individuals;
	int populationSize;
	int individualSize;
};

