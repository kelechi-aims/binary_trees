#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * binary_tree_is_max_heap - func that checks if a binary tree is a max heap
 * @tree: pointer to the root
 * @max_value: maximum value that the tree
 * Return: 1 if max heap, 0 otherwise
 **/
int binary_tree_is_max_heap(const binary_tree_t *tree, int max_value)
{
	if (!tree)
		return 1;

	if (tree->n >= max_value)
		return 0;

	if (!binary_tree_is_max_heap(tree->left, tree->n) ||
	    !binary_tree_is_max_heap(tree->right, tree->n))
		return 0;

	return 1;
}

/**
 * binary_tree_is_heap - func checks if a binary tree is a heap
 * @tree: pointer to the root
 * Return: 1 if a heap, 0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return 0;

	if (!binary_tree_is_complete(tree))
		return 0;

	return binary_tree_is_max_heap(tree, INT_MAX);
}

