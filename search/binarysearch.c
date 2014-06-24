#include <stdio.h>
#include <stdlib.h>

int binarysearch(int *collection, int searched);

int main(int argc, char *argv[]) {
	int *collection, i, nbElements, searched, searchedIndex;

	if (argc < 3) {
		return 0;
	}

	nbElements = argc-2;
	collection = (int*) malloc(nbElements * sizeof(int));
	for (i = 2; i < argc; i++) {
		collection[i - 2] = atoi(argv[i]);
	}

	searched = atoi(argv[1]);
	searchedIndex = binarysearch(collection, searched);

	printf("searched: %d; index: %d\n", searched, searchedIndex);

	return 1;
}


int binarysearch(int *collection, int searched)
{
	return -1;
}
