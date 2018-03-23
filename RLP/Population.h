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
	void calculateFitness();
	int** getIndividuals();
	int* getTopPercent();
	int getFitness();
	int getPopulationSize();
	int getIndividualSize();
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

