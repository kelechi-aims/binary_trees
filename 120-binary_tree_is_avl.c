#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	return ((left_height > right_height) ? left_height : right_height);
}

/**
 * binary_tree_avl- Checks if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum allowed value for nodes in the tree.
 * @max: The maximum allowed value for nodes in the tree.
 * Return: 1 if @tree is a valid BST, 0 otherwise.
 */
int binary_tree_avl(const binary_tree_t *tree, int min, int max)
{
	size_t l_height, r_height, d;

	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		l_height = binary_tree_height(tree->left);
		r_height = binary_tree_height(tree->right);
		d = l_height > r_height ? l_height - r_height : r_height - l_height;
		if (d > 1)
			return (0);
		return (binary_tree_avl(tree->left, min, tree->n - 1) &&
			binary_tree_avl(tree->right, tree->n + 1, max));
	}
	return (1);
}


/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if @tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_avl(tree, INT_MIN, INT_MAX));
}
