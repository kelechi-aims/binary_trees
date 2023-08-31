#include "binary_trees.h"
#include <stdlib.h>
/**
 * tree_height - func that measures the height of a binary tree
 * @tree: pointer to the root
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	if (!tree)
		return (0);

	size_t left_height = tree_height(tree->left);
	size_t right_height = tree_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * _preorder_find_last - func that finds the last node
 * @tree: pointer to the root
 * @node: pointer that points to last node
 * @height: height of the tree
 * Return: void
 */
void _preorder_find_last(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
	{
		*node = tree;
		return;
	}
	_preorder_find_last(tree->left, node, height - 1);
	_preorder_find_last(tree->right, node, height - 1);
}

/**
 * heap_extract - func that extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);

	heap_t *heap_r = *root;
	int value = heap_r->n;

	if (!heap_r->left && !heap_r->right)
	{
		free(heap_r);
		*root = NULL;
		return (value);
	}
	size_t max_height = tree_height(heap_r);
	heap_t *last_node = NULL;

	_preorder_find_last(heap_r, &last_node, max_height - 1);

	heap_r->n = last_node->n;

	if (last_node->parent->right)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;
	free(last_node);

	heapify(heap_r);
	*root = heap_r;

	return (value);
}
