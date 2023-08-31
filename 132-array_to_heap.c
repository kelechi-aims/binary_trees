#include "binary_trees.h"

/**
 * array_to_heap - function that builds binary Heap tree from an array.
 * @array: pointer to the first element.
 * @size: number of elements.
 * Return: pointer to root, or NULL if fail.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	heap_t *root = NULL;

	for (size_t idx = 0; idx < size; idx++)
	{
		if (!heap_insert(&root, array[idx]))
		{
			binary_tree_delete(root);
			return (NULL);
		}
	}
	return (root);
}

