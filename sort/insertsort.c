#include <stdio.h>
#include <stdlib.h>

void insertsort(int *collection, const int nbElements);

int main(int argc, char *argv[]) {
	int *collection, i, nbElements;

	nbElements = argc-1;
	collection = (int*) malloc(nbElements * sizeof(int));
	for (i = 1; i < argc; i++) {
		collection[i-1] = atoi(argv[i]);
	}

	insertsort(collection, nbElements);

	for (i = 0; i < nbElements; ++i) {
		printf("%d\n", collection[i]);
	}

	free(collection);
	return 1;
}

void insertsort(int *collection, const int nbElements) {
	int i, j, k, tmp;

	i = 0;
	while (i < nbElements) {
		for (j = 0; j < i; ++j) {
			if (collection[j] > collection[i]) {
				tmp = collection[i];
				for (k = i; k > j; --k) {
					collection[k] = collection[k - 1];
				}
				collection[j] = tmp;
			}
		}
		++i;
	}
}
