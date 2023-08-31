#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * binary_tree_is_heap - function that checks if a binary tree is a max heap
 * @tree: pointer to the root
 * Return: 1 if max heap, 0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
	{
		if (tree->left->n > tree->n)
			return (0);
		if (!binary_tree_is_heap(tree->left))
			return (0);
	}
	if (tree->right)
	{
		if (tree->right->n > tree->n)
			return (0);
		if (!binary_tree_is_heap(tree->right))
			return (0);
	}
	return (1);
}
