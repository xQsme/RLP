#include "Population.h"

Population::Population() {

}

void Population::libertarMemoria()
{
	problem.libertarMemoria();
	for (int i = 0; i < populationSize; i++) {
		delete[] individuals[i];
	}
	delete[] individuals;
}

void Population::setUpPopulation(int populationSize, int seed, int elitism, int mutation, std::ifstream& stream) {
	problem.setUpProblem(stream);
	if (populationSize > 0) { // Se existem individuos
		individuals = (int**)malloc(sizeof(int*)*populationSize); //instanciar matriz
		if (problem.getTotal() > 0) { //Se o ficheiro foi bem lido
			srand(seed);
			for (int i = 0; i < populationSize; i++) { //para cada individuo
				individuals[i] = (int*)malloc(sizeof(int*)*problem.getTotal()); //instancia solução (vetor com o tamanho dos nós existentes)
				for (int j = 0; j < problem.getTotal(); j++) { //cada nó do individuo fica com 0 ou 1
					individuals[i][j] = rand() % 2;
				}
			}
		}
	}
	this->seed = seed;
	this->elitism = elitism * 0.01;
	this->mutation = mutation * 0.01;
	this->populationSize = populationSize;
	this->individualSize = problem.getTotal();
}

void Population::setUpPopulation(int populationSize, int seed, int elitism, int mutation) {
	for (int i = 0; i < this->populationSize; i++) {
		free(individuals[i]);
	}
	free(individuals);
	if (populationSize > 0) {
		individuals = (int**)malloc(sizeof(int*)*populationSize);
		if (problem.getTotal() > 0) {
			srand(seed);
			for (int i = 0; i < populationSize; i++) {
				individuals[i] = (int*)malloc(sizeof(int*)*individualSize);
				for (int j = 0; j < problem.getTotal(); j++) {
					individuals[i][j] = rand() % 2;
				}
			}
		}
	}
	this->seed = seed;
	this->elitism = elitism * 0.01;
	this->mutation = mutation * 0.01;
	this->populationSize = populationSize;
}

void Population::calculateFitness() {

	int* fitnesses = (int*)malloc(sizeof(int)*populationSize); //Vetor de fitnesses

	int currentFitness;
	int match; //Verificar se o nó está ligado

	for (int i = 0; i < populationSize; i++) { //para cada individuo
		currentFitness = 0;
		for (int y = 0; y < problem.getTotal(); y++) { //y é a linha do problema
			match = 0;
			for (int x = 0; x < problem.getTotal(); x++) { //para cada nó (tanto no problema como no individuo)
				if (problem.getNodes()[y][x] == 1) { // se existe ligação no nó
					if (individuals[i][x] == 1) { //se o nó tem regenerador
						match++; //nó regenerado
						break; //escusa de verificar se tem mais ligações
					}
				}
			}
			if (match == 0) { //o nó não está ligado a um regenerador
				currentFitness += 500; //é pior estar não regenerado que ter um regenerador a mais
			}
		}
		for (int j = 0; j < individualSize; j++) {
			if (individuals[i][j] == 1) { // por cada regenerador que o invididuo tem
				if (problem.hasWeights()) {
					currentFitness += problem.getWeights()[j] * 100;
				}else{
					currentFitness += 100;
				}
			}
		}
		fitnesses[i] = currentFitness;
	}

	for (int i = 0; i < populationSize; i++) //Ordenar fitness crescente e população por fitness crescente
	{
		for (int j = 0; j < populationSize - 1; j++)
		{
			if (fitnesses[j] > fitnesses[j + 1]) //Se anterior maior que seguinte
			{
				int temp = fitnesses[j];
				int* tempIndividual = individuals[j];
				fitnesses[j] = fitnesses[j + 1];
				fitnesses[j + 1] = temp;
				individuals[j] = individuals[j + 1];
				individuals[j + 1] = tempIndividual; //seguinte passa a anterior
			}
		}
	}

	fitness = fitnesses[0];
	disconnected = 0;
	regenerators = 0;
	//a mesma logica do calculo do fitness mas so para o melhor individuo
	for (int y = 0; y < problem.getTotal(); y++) {
		match = 0;
		for (int x = 0; x < problem.getTotal(); x++) {
			if (problem.getNodes()[y][x] == 1) {
				if (individuals[0][x] == 1) {
					match++;
					break;
				}
			}
		}
		if (match == 0) {
			disconnected++; //guarda o numero de ligações sem regenerador
		}
	}
	for (int j = 0; j < individualSize; j++) {
		if (individuals[0][j] == 1) {
			regenerators++; //guarda o total de regeneradores
		}
	}

	delete[] fitnesses;
}

int** Population::getIndividuals() {
	return individuals;
}

int Population::getFitness() {
	return fitness;
}

int Population::getSeed() {
	return seed;
}

float Population::getElitism() {
	return elitism;
}

float Population::getMutation() {
	return mutation;
}

int Population::getDisconnected() {
	return disconnected;
}
int Population::getRegenerators() {
	return regenerators;
}

int Population::getPopulationSize() {
	return populationSize;
}

int Population::getIndividualSize() {
	return individualSize;
}

int Population::getTotal()
{
	return problem.getTotal();
}

int Population::getConnections()
{
	return problem.getConnections();
}