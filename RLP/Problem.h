#pragma once
#include <fstream> 
#include <sstream>
using namespace std;
ref class Problem
{
public:
	Problem(ifstream stream);
	virtual ~Problem();
private:
	int **nodes;
};

