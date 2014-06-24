#include <stdlib.h>
#include <stdio.h>

// compiled with:  gcc -Wall -g quicksort.c -o quicksort

void quicksort(int *collection, const int nbElements, int start, int pivot);
int _permutations(int *collection, int start, int pivot);

int main(int argc, char* argv[]) {
	int *collection, i, nbElements;

	collection = (int *) malloc((argc - 1) * sizeof(int));
	nbElements = argc - 1;
	for (i = 1; i < argc; ++i) {
		collection[i - 1] = atoi(argv[i]);
	}

	quicksort(collection, nbElements, 0, nbElements - 1);

	for (i = 0; i < nbElements; ++i) {
		printf("%d\n", collection[i]);
	}

	return 1;
}

int _permutations(int *collection, int start, int pivot) {
	int i, tmp;

	i = start;
	while (i < pivot) {
		if (collection[i] < collection[pivot]) {
			++i;
		}
		else {
			tmp = collection[pivot];
			collection[pivot] = collection[i];
			collection[i] = collection[pivot - 1];
			collection[pivot - 1] = tmp;
			--pivot;
		}
	}

	return pivot;
}

void quicksort(int *collection, const int nbElements, int start, int pivot) {
	if (start < pivot - 1) {
		pivot = _permutations(collection, start, pivot);
		quicksort(collection, nbElements, start, pivot - 1);
		quicksort(collection, nbElements, pivot + 1, nbElements - 1);
	}
}
