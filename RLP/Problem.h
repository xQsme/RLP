#pragma once
#include <fstream> 
#include <sstream>
using namespace std;
ref class Problem
{
public:
	Problem(std::ifstream& stream);
	virtual ~Problem();
	int **getNodes();
	int *getWeights();
	int hasWeights();
	int getTotal();
	int getConnections();
private:
	int **nodes;
	int *weights;
	int hasWeight = 0;
	int total=0;
	int connections = 0;
};

