#pragma once
#include <sstream>
using namespace std;
ref class Individual
{
public:
	Individual(int size);
	void libertarMemoria();
	int* getNodes();
	int getTotal();
private:
	int* nodes;
	int total;
};

