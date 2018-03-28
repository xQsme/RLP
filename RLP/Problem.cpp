#include "Problem.h"

Problem::Problem() {

}

void Problem::libertarMemoria()
{
	delete[] weights;
	for (int i = 0; i < total; i++) {
		delete[] nodes[i];
	}
	delete[] nodes;
}

void Problem::setUpProblem(std::ifstream& stream)
{
	free(weights);
	for (int i = 0; i < total; i++) {
		delete[] nodes[i];
	}
	free(nodes);
	int check = 0; //Verificar se tem pesos
	int done = 0; //Ja leu pesos todos
	int skipped = 0; //Ja passou a linha após ler os pesos
	int count = 0; //Linha do ficheiro
	int idx = 0; //Linha na matriz
	total = 0;
	connections = 0;
	std::string line;
	while (std::getline(stream, line)) //Para cada linha do ficheiro
	{
		count++;
		if (total == 0 || connections == 0 || check == 0) { //As 3 primeiras linhas
			if (connections != 0) { //Verificar se tem pesos
				check = 1;
				if (line.find("Weight") != -1) {
					hasWeight = 1;
					weights = (int*)malloc(total * sizeof(int));
				}
				else {
					hasWeight = 0;
				}
			}
			else if (total != 0) { //Total de ligações
				if (line.find("=") == -1) {
					throw std::invalid_argument("wrong file!");
				}
				if (line.find(";") == -1) {
					connections = stoi(line.substr(line.find("=") + 2, line.length()));
				}
				else {
					connections = stoi(line.substr(line.find("=") + 1, line.find(";") - 1));
				}
			}
			else { //Total de nós
				if (line.find(";") == -1) { 
					total = stoi(line.substr(line.find("=") + 2, line.length()));
				}
				else {
					total = stoi(line.substr(line.find("=") + 1, line.find(";") - 1));
				}
				nodes = (int**)malloc(sizeof(int*) * total);

				for (int index = 0; index < total; ++index) {
					{
						nodes[index] = (int*)malloc(total * sizeof(int));
					}
				}

			}
		}
		else {
			if (done == 1 && skipped == 0) { //ja leu pesos e ainda nao passou linha
				skipped = 1;
			}
			else { //Nao tem pesos ou ja passou linha
				if ((count > 4 && count % 2 != 0 && hasWeight == 0) || done == 1) { //Linhas impares para quando nao tem pesos, todas as linhas quando ja leu pesos
					int value;
					int pos = 0;
					std::stringstream iss(line);
					while (iss >> value) {
						nodes[idx][pos++] = value == 0 ? 0 : 1;
					}
					if (++idx == total) {
						break;
					}
				}
				else if (hasWeight == 1) { //Ler os pesos
					weights[idx++] = stoi(line);
					if (idx == total) {
						idx = 0;
						done = 1;
					}
				}
			}
		}
	}
}

int **Problem::getNodes()
{
	return nodes;
}

int *Problem::getWeights()
{
	return weights;
}

int Problem::hasWeights()
{
	return hasWeight;
}

int Problem::getTotal()
{
	return total;
}

int Problem::getConnections()
{
	return connections;
}