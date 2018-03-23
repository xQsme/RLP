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
	void calculateFitness();
	int getFitness();
	int* getTopPercent();
	int getTotal();
	int getConnections();
private:
	Problem problem;
	int** individuals;
	int* topPercent;
	int fitness;
	int populationSize;
	int individualSize;
};

