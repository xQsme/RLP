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
	int getTotal();
	int getConnections();
private:
	int **nodes;
	int total=0;
	int connections = 0;
};

