#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @flag: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void create_tree(avl_t **node, int *array, size_t size, int flag)
{
	size_t mid;

	if (size == 0)
		return;

	mid = (size / 2);
	mid = (size % 2 == 0) ? mid - 1 : mid;

	if (flag == 1)
	{
		(*node)->left = binary_tree_node(*node, array[mid]);
		create_tree(&((*node)->left), array, mid, 1);
		create_tree(&((*node)->left), array + mid + 1, (size - 1 - mid), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[mid]);
		create_tree(&((*node)->right), array, mid, 1);
		create_tree(&((*node)->right), array + mid + 1, (size - 1 - mid), 2);
	}
}


/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of element in the array
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t mid;

	if (size == 0)
		return (NULL);
	mid = size / 2;
	mid = (size % 2 == 0) ? mid - 1 : mid;

	root = binary_tree_node(NULL, array[mid]);

	create_tree(&root, array, mid, 1);
	create_tree(&root, array + mid + 1, (size - 1 - mid), 2);

	return (root);
}

