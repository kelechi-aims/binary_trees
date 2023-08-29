#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a given node is a root
 * @node: Pointer to the node to check
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (node->left == NULL && node->right == NULL);
}
