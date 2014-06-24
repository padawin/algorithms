#include <stdlib.h>
#include <stdio.h>

void selectsort(int *collection, const int nbElements);

int main(int argc, char *argv[]) {
	int *collection, i, nbElements;

	nbElements = argc-1;
	collection = (int*) malloc(nbElements * sizeof(int));
	for (i = 1; i < argc; i++) {
		collection[i-1] = atoi(argv[i]);
	}

	selectsort(collection, nbElements);

	for (i = 0; i < nbElements; ++i) {
		printf("%d\n", collection[i]);
	}

	return 1;
}

void selectsort(int *collection, const int nbElements) {
	int i, j, min, tmp;

	i = 0;
	while (i < nbElements) {
		min = -1;
		for (j = i; j < nbElements; ++j) {
			if (min == -1 || collection[j] < collection[min]) {
				min = j;
			}
		}
		if (min != i) {
			tmp = collection[i];
			collection[i] = collection[min];
			collection[min] = tmp;
		}
		i++;
	}
}
