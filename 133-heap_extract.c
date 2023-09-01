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
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int extimated_value;
	heap_t *tmp_old, *tmp_new;

	if (root == NULL)
		return;

	tmp_old = root;

	while (1)
	{
		if (!tmp_old->left)
			break;
		if (!tmp_old->right)
			tmp_new = tmp_old->left;
		else
		{
			if (tmp_old->left->n > tmp_new->right->n)
				tmp_new = tmp_old->left;
			else
				tmp_new = tmp_old->right;
		}
		if (tmp_old->n > tmp_new->n)
			break;
		extimated_value = tmp_old->n;
		tmp_old->n = tmp_new->n;
		tmp_new->n = value;
		tmp_old = tmp_new;
	}
}

/**
 * heap_extract - func that extracts root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: extracted value
 **/
int heap_extract(heap_t **root)
{
	int extimated_value;
	heap_t *heap_r, *node;

	if (root == NULL || *root == NULL)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (extimated_value);
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
	return (extimated_value);
}
