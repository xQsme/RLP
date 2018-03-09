#include "Problem.h"

Problem::Problem(std::ifstream& stream)
{
	int count = 0;
	int idx = 0;
	std::string line;
	while (std::getline(stream, line))
	{
		count++;
		if (total == 0 || connections == 0) {
			if (total != 0) {
				connections = stoi(line.substr(line.find("=") + 1, line.find(";") - 1));
			}
			else {
				total = stoi(line.substr(line.find("=") + 1, line.find(";") - 1));
				nodes = (int**)malloc(sizeof(int*)*total);
				for (int index = 0; index<total; ++index)
				{
					nodes[index] = (int*)malloc(total * sizeof(int));
				}
			}

		}
		else {
			if (count > 4 && count % 2 != 0) {
				int value;
				int pos = 0;
				std::stringstream iss(line);
				while (iss >> value) {
					nodes[idx][pos++] = value == 0 ? 0 : 1;
				}
				idx++;
				if (idx == total) {
					break;
				}
			}
		}
	}
}


Problem::~Problem()
{
}

int **Problem::getNodes()
{
	return nodes;
}

int Problem::getTotal()
{
	return total;
}

int Problem::getConnections()
{
	return connections;
}