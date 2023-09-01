#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - func that measures the height of a binary tree
 * @tree: pointer to the root
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_h = 1 + tree_height(tree->left);

	if (tree->right)
		right_h = 1 + tree_height(tree->right);

	if (left_h > right_h)
		return (left_h);
	return (right_h);
}
/**
 * tree_size_h - func that measures sum of heights of a binary tree
 * @tree: pointer to the root
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_h = 1 + tree_size_h(tree->left);

	if (tree->right)
		right_h = 1 + tree_size_h(tree->right);

	return (left_h + right_h);
}

/**
 * _preorder - func that goes through a binary tree
 * @tree: pointer to the root
 * @node: pointer to last note pointer
 * @height: height of tree
 * Return: void
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (tree == NULL)
		return;

	if (height == NULL)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - func that heapifies max binary heap
 * @root: pointer to binary heapi
 * Return: void
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

/**
 * heap_extract - func that extracts root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: extracted value
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}
