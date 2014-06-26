#include <stdio.h>
#include <stdlib.h>

int binarysearch(int *collection, int searched, int start, int end);

/**
 * In this version we suppose the collection is already sorted.
 * A preliminary sort will be done in a later version.
 */
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
	searchedIndex = binarysearch(collection, searched, 0, nbElements);

	printf("searched: %d; index: %d\n", searched, searchedIndex);

	return 1;
}


int binarysearch(int *collection, int searched, int start, int end)
{
	int searchedIndex;

	searchedIndex = start + (end - start) / 2;

	if (start == end && collection[searchedIndex] != searched) {
		return -1;
	}

	if (collection[searchedIndex] == searched) {
		return searchedIndex;
	}
	else if (collection[searchedIndex] > searched) {
		return binarysearch(collection, searched, start, searchedIndex - 1);
	}
	else if (collection[searchedIndex] < searched) {
		return binarysearch(collection, searched, searchedIndex + 1, end);
	}
}
