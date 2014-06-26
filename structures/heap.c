#include <stdio.h>
#include <stdlib.h>

int add_to_heap(int *heap, int heap_max_size, int heap_size, int element);

int main(int argc, char *argv[]) {
	int *collection,
		i, heap_max_size;

	heap_max_size = argc - 1;
	collection = (int *) malloc((heap_max_size) * sizeof(int));
	for (i = 1; i < argc; ++i) {
		add_to_heap(collection, heap_max_size, i - 1, atoi(argv[i]));
	}


	free(collection);
	return 1;
}

int add_to_heap(int *heap, int heap_max_size, int heap_size, int element) {
	unsigned int i, parent;
	int tmp;

	if (heap_size == heap_max_size) {
		return -1;
	}

	heap[heap_size] = element;

	if (heap_size == 0) {
		return 0;
	}

	i = heap_size;
	while (i > 0) {
		parent = (i - 1) / 2;
		if (heap[i] > heap[parent]) {
			tmp = heap[i];
			heap[i] = heap[parent];
			heap[parent] = tmp;
		}
		i = parent;
	}
	return 1;
}
