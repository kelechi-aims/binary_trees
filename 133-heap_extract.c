#include "binary_trees.h"

/**
 * tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root
 * Return: Height, or 0 if NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t left_height = tree_height(tree->left);
	size_t right_height = tree_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * heapify - function that heapifies a max binary heap
 * @root: pointer to binary heap root
 */
void heapify(heap_t *root)
{
	if (!root)
		return;

	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left && left->n > largest->n)
	largest = left;

	if (right && right->n > largest->n)
	largest = right;

	if (largest != root)
	{
		int temp = root->n;

		root->n = largest->n;
		largest->n = temp;
		heapify(largest);
	}
}

/**
 * heap_extract - fucntion that extracts root node from a Binary Heap
 * @root: pointer to the heap
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);

	int extracted_value = (*root)->n;

	heap_t *last_node;

	last_node = *root;

	while (last_node->left || last_node->right)
	{
		if (!last_node->right || last_node->left->n > last_node->right->n)
		last_node = last_node->left;
	else
		last_node = last_node->right;
	}

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
	return (extracted_value);
	}
	(*root)->n = last_node->n;
	if (last_node->parent->left == last_node)
	last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	free(last_node);
	heapify(*root);

	return (extracted_value);
}
