#include "binary_trees.h"
#include <limits.h>

/**
 * bst_helper - Helper function to recursively check if a binay tree
 * is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: The minimum value the nodes in the tree must have
 * @max: The maximum value the nodes in the tree must have
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (bst_helper(tree->left, min, tree->n) &&
		bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_helper(tree, INT_MIN, INT_MAX));
}
