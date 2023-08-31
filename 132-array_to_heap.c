#include "binary_trees.h"

/**
 * array_to_heap - function that builds binary Heap tree from an array.
 * @array: pointer to the first element.
 * @size: number of elements.
 * Return: pointer to root, or NULL if fail.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int idx;
	heap_t *root = NULL;

	for (idx = 0; idx < size; idx++)
		heap_insert(&root, array[idx]);

	return (root);
}

