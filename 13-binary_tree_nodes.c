#include "binary_trees.h"

/**
 * binary_tree_nodes - function that counts the nodes with at least 1 child.
 * @tree: a pointer to the root.
 * Return: if NULL, return 0.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

    if (tree != NULL)
    {
        if (tree->left || tree->right)
            count = binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1;
    }
    return count;

}
