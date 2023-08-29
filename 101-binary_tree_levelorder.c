#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	binary_tree_t *current;
	int front, rear;

	if (tree == NULL || func == NULL)
		return;
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return;
	front = 0;
	rear = 0;
	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
	free(queue);
}
