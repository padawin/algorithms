#include <stdio.h>
#include <stdlib.h>

void display_heap(int *heap, int heap_size);
int add_to_heap(int *heap, int heap_max_size, int heap_size, int element);
int remove_from_heap(int *heap, int heap_size, int index_to_remove);

int main(int argc, char *argv[]) {
	int *collection,
		i, heap_max_size;

	heap_max_size = argc - 1;
	collection = (int *) malloc((heap_max_size) * sizeof(int));
	for (i = 1; i < argc; ++i) {
		add_to_heap(collection, heap_max_size, i - 1, atoi(argv[i]));
	}

	//display the array
	display_heap(collection, heap_max_size);

	heap_max_size = remove_from_heap(collection, heap_max_size, 0);
	display_heap(collection, heap_max_size);

	free(collection);
	return 1;
}

void display_heap(int *heap, int heap_size) {
	int i;

	for (i = 0; i < heap_size; ++i) {
		printf("%d ", heap[i]);
	}
	printf("\n");
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

int remove_from_heap(int *heap, int heap_size, int index_to_remove) {
	if (index_to_remove >= heap_size) {
		return -1;
	}

	short int must_go_down = 1;
	int tmp, left, right;

	--heap_size;
	heap[index_to_remove] = heap[heap_size];
	heap = realloc(heap, (heap_size) * sizeof(int));

	while (must_go_down == 1) {
		left = 2 * index_to_remove + 1;
		right = 2 * index_to_remove + 2;
		if (left < heap_size && heap[index_to_remove] < heap[left]) {
			tmp = heap[index_to_remove];
			heap[index_to_remove] = heap[left];
			heap[left] = tmp;
		}
		else if (right < heap_size && heap[index_to_remove] < heap[right]) {
			tmp = heap[index_to_remove];
			heap[index_to_remove] = heap[right];
			heap[right] = tmp;
		}
		else {
			must_go_down = 0;
		}
	}

	return heap_size;
}
