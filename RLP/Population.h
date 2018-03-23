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
	void setUpPopulation(int populationSize, int seed);
	void calculateFitness();
	int** getIndividuals();
	int getFitness();
	int getDisconnected();
	int getRegenerators();
	int getPopulationSize();
	int getIndividualSize();
	int getTotal();
	int getConnections();
private:
	Problem problem;
	int** individuals;
	int fitness;
	int disconnected;
	int regenerators;
	int populationSize;
	int individualSize;
};

