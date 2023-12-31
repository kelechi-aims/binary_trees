#include "binary_trees.h"

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree.
 * @tree: a pointer to the root.
 * Return: if NULL, return 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_total = 0, leaves_left = 0, leaves_right = 0;

	if (tree == NULL)
		return (0);
	else if (!tree->left && !tree->right)
		return (1);
	leaves_left = binary_tree_leaves(tree->left);
	leaves_right = binary_tree_leaves(tree->right);
	leaves_total = leaves_left + leaves_right;

	return (leaves_total);
}
