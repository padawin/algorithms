#include <stdio.h>
#include <stdlib.h>

int add_to_heap(int *heap, int element);

int main(int argc, char *argv[]) {
	int *collection, i, nbElements;

	collection = (int *) malloc((argc - 1) * sizeof(int));
	nbElements = argc - 1;
	for (i = 1; i < argc; ++i) {
		collection[i - 1] = atoi(argv[i]);
	}

	for (i = 0; i < nbElements; ++i) {
		printf("%d\n", collection[i]);
	}

	free(collection);
	return 1;
}

int add_to_heap(int *heap, int element) {

	return 1;
}
