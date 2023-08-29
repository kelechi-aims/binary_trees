#include "binary_trees.h"

/**
 * binary_tree_depth - mfunction that measures the depth of a node in a binary tree.
 * @tree: a pointer to the root
 * Return: if NULL, return 0.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree && tree->parent)
	{
		depth = binary_tree_depth(tree->parent) + 1;
		return (depth);
	}
	return (0);
}
