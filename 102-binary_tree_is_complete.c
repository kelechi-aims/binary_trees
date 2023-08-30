#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue, *current;
	int front, rear, hasEmptychild;

	if (tree == NULL)
		return (0);
	queue = malloc(sizeof(const binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);
	front = 0;
	rear = 0;
	hasEmptychild = 0;

	queue[rear++] = tree;
	while (front < rear)
	{
		current = queue[front++];
		if (current->left == NULL)
			hasEmptychild = 1;
		else if (hasEmptychild)
		{
			free(queue);
			return (0);
		}
		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right == NULL)
			hasEmptychild = 1;
		else if (hasEmptychild)
		{
			free(queue);
			return (0);
		}
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
	free(queue);
	return (1);
}
