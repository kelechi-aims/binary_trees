#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max_heap - function that checks if a subtree is a max heap
 * @tree: pointer to the root
 * @max_value: the maximum allowed value
 * Return: 1 if the subtree is a max heap, 0 otherwise
 **/
int check_max_heap(const binary_tree_t *tree, int max_value)
{
	if (!tree)
		return (1);

	if (tree->n >= max_value)
		return (0);

	return (check_max_heap(tree->left, tree->n) &&
			check_max_heap(tree->right, tree->n));
}

/**
 * binary_tree_is_heap - function that checks if a binary tree
 * @tree: pointer to the root node of the tree
 * Return: 1 if the tree is a max heap, 0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int is_complete, is_max_heap;

	if (!tree)
		return (0);

	is_complete = binary_tree_is_complete(tree);
	if (!is_complete)
		return (0);

	is_max_heap = check_max_heap(tree, tree->n);
	return (is_max_heap);
}
