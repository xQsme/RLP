#pragma once
#include <fstream> 
#include <sstream>
using namespace std;
ref class Problem
{
public:
	Problem();
	virtual ~Problem();
	void setUpProblem(std::ifstream& stream);
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

