#pragma once
#include "Individual.h"
#include <sstream>
using namespace std;
ref class Population
{
public:
	Population(int size);
	void libertarMemoria();
	Individual^ getIndividuals();
	int getPopulationSize();
private:
	Individual^ individuals;
	int populationSize;
};

