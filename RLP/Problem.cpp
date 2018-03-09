#include "Problem.h"
#include <fstream> 
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int **nodes;

Problem::Problem(ifstream stream)
{
	int total = 0;
	int count = 0;
	int idx = 0;
	std::string line;   
	while (std::getline(stream, line)) 
	{
		if (total == 0) {
			total=stoi(line.substr(line.find("="), line.find(";")));
			nodes = (int**) malloc(sizeof(int*)*total);
			for (int index = 0; index<total; ++index)
			{
				nodes[index] = (int*)malloc(total * sizeof(int));
			}
		}
		else {
			if (count > 4) {
				int value;
				int pos = 0;
				std::stringstream iss(line);
				while (iss >> value) {
					nodes[idx][pos++] = value;
				}

				if (idx == total - 1) {
					break;
				}
			}
		}
	}
}


Problem::~Problem()
{
}