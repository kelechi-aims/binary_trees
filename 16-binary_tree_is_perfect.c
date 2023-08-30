#include "binary_trees.h"

/**
 * tree_is_perfect - function that says if a tree is perfect or not
 * @tree: tree to check
 * Return: 0
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree->left && tree->right)
	{
		left = 1 + tree_is_perfect(tree->left);
		right = 1 + tree_is_perfect(tree->right);
		if (right == left && right && left)
			return (right);
		return (0);
	}
	else if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * binary_tree_is_perfect - function that says it a binary_tree is perfect
 * @tree: pointer to check
 * Return: 1 if perfect, or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int count = 0;

	if (!tree)
	{
		return (0);
	}
	else
	{
		count = tree_is_perfect(tree);
		if (count)
		{
			return (1);
		}
		return (0);
	}
}
