#include "binary_trees.h"
#include <stdlib.h>

/**
 * calculate_tree_height - func that measures height of binary tree
 * @tree: pointer to the root
 * Return: Height or 0 if tree is NULL
 */
size_t calculate_tree_height(const heap_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_h = 1 + calculate_tree_height(tree->left);

	if (tree->right)
		right_h = 1 + calculate_tree_height(tree->right);

	if (left_h > right_h)
		return (left_h);
	return (right_h);
}

/**
 * calculate_tree_size - func that measures sum of heights of a binary tree
 * @tree: pointer to the root
 * Return: Height or 0 if tree is NULL
 */
size_t calculate_tree_size(const binary_tree_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_h = 1 + calculate_tree_size(tree->left);
	if (tree->right)
		right_h = 1 + calculate_tree_size(tree->right);
	return (left_h + right_h);
}

/**
 * traverse_preorder - func that goes through a binary tree
 * @tree: pointer to the root
 * @target_node: poniter to pointer of last node
 * @remaining_height: height of the tree
 * Return: void
 */
void traverse_preorder(heap_t *tree, heap_t **target_node,
		size_t remaining_height)
{
	if (!tree)
		return;

	if (!remaining_height)
		*target_node = tree;
	remaining_height--;

	traverse_preorder(tree->left, target_node, remaining_height);
	traverse_preorder(tree->right, target_node, remaining_height);
}

/**
 * heapify_tree - function that heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify_tree(heap_t *root)
{
	int tmp_value;
	heap_t *tmp_node1, *tmp_node2;

	if (!root)
		return;

	tmp_node1 = root;

	while (1)
	{
		if (!tmp_node1->left)
			break;
		if (!tmp_node1->right)
			tmp_node2 = tmp_node1->left;
		else
		{
			if (tmp_node1->left->n > tmp_node1->right->n)
				tmp_node2 = tmp_node1->left;
			else
				tmp_node2 = tmp_node1->right;
		}
		if (tmp_node1->n > tmp_node2->n)
			break;
		tmp_value = tmp_node1->n;
		tmp_node1->n = tmp_node2->n;
		tmp_node2->n = tmp_value;
		tmp_node1 = tmp_node2;
	}
}

/**
 * heap_extract_value - func that extracts root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: extracted value
 **/
int heap_extract_value(heap_t **root)
{
	int extracted_value;
	heap_t *heap_right, *extracted_node;

	if (!root || !*root)
		return (0);
	heap_right = *root;
	extracted_value = heap_right->n;
	if (!heap_right->left && !heap_right->right)
	{
		*root = NULL;
		free(heap_right);
		return (extracted_value);
	}
	traverse_preorder(heap_right, &extracted_node,
			calculate_tree_height(heap_right));

	heap_right->n = extracted_node->n;

	if (extracted_node->parent->right)
		extracted_node->parent->right = NULL;
	else
		extracted_node->parent->left = NULL;
	free(extracted_node);
	heapify_tree(heap_right);
	*root = heap_right;
	return (extracted_value);
}
