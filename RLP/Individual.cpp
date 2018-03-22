#include "Individual.h"

Individual::Individual(int size) {
	if (size > 0) {
		nodes = (int*) malloc(sizeof(int)*size);
	}
	total = size;
}

void Individual::libertarMemoria()
{
	delete[] nodes;
}

int* Individual::getNodes() {
	return nodes;
}

int Individual::getTotal() {
	return total;
}