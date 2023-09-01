#include "binary_trees.h"

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to the root
 * Return: Size of the tree or 0 if NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + tree_size(tree->left);

	if (tree->right)
		r_height = 1 + tree_size(tree->right);

	return (l_height + r_height);
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
	size_t i;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;
	sorted_array = malloc(sizeof(int) * (*size));
	if (!sorted_array)
		return (NULL);

	for (i = 0; heap; i++)

		sorted_array[i] = heap_extract(&heap);
	return (sorted_array);
}
