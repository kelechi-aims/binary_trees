#include "binary_trees.h"

/**
 * avl_rotate - Performs value insertion on an AVL tree
 * @tree: A double pointer to the root node of the AVL tree to insert into
 * @child: A double pointer to store the new node
 * @parent: The parent node of the current inserting node
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the new root node after insertion, or NULL on failure
 */
avl_t *avl_rotate(avl_t **tree, avl_t **child,	avl_t *parent, int value)
{
	int bal_factor;

	if (*tree == NULL)
		return (*child = binary_tree_node(parent, value));
	if ((*tree)->n > value)
	{
		(*tree)->left = avl_rotate(&(*tree)->left, child, *tree, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_rotate(&(*tree)->right, child, *tree, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bal_factor = binary_tree_balance(*tree);
	if (bal_factor > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	if (bal_factor < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	if (bal_factor > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	if (bal_factor < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * for inserting the value
 * @value: The value to store in the node to be inserted
 * Return: A  pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *child = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_rotate(tree, &child, *tree, value);
	return (child);
}
