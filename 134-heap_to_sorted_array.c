#include "binary_trees.h"

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to the root
 * Return: Size of the tree or 0 if NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * copy_heap_to_array - copies heap elements to an array in descending order
 * @heap: pointer to the root node of the heap
 * @array: pointer to the array
 * @index: current index in the array
 */
void copy_heap_to_array(heap_t *heap, int *array, int *index)
{
	if (!heap)
		return;

	array[*index] = heap->n;
	(*index)++;

	copy_heap_to_array(heap->left, array, index);
	copy_heap_to_array(heap->right, array, index);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array
 * @heap: pointer to the root
 * @size: address to store size
 * Return: pointer to array sorted
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t array_size;

	if (!heap || !size)
	return (NULL);

	array_size = tree_size(heap);
	sorted_array = malloc(sizeof(int) * array_size);
	if (!sorted_array)
		return (NULL);

	*size = array_size;
	copy_heap_to_array(heap, sorted_array, &(int){0});

	return (sorted_array);
}
