#include "binary_trees.h"

/**
 * inorder_successor - Returns the node with the smallest value in a BST.
 * @node: A pointer to the root node of the subtree.
 * Return: A pointer to the node with the smallest value.
 */
bst_t *inorder_successor(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_delete - Deletes a node from a binary search tree
 * @root: A pointer to the root node of the BST
 * @node: A pointer to the node to delete from the BST
 * Return: A pointer to the new root node after deletion
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);

	}
	successor = inorder_successor(node->right);
	node->n = successor->n;
	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Removes a node from BST
 * @root: A pointer to the root of the BST to remove a node
 * @node: A pointer to the current node in the BST
 * @value: The value to remove from the BST
 * Return: A pointer to the root node after deletion
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}
/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 * Return: A pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
