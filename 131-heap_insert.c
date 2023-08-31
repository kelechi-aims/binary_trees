#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree.
 * @tree: pointer to meausred size.
 * Return: Size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1;
}

/**
 * heap_insert - function that inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node.
 * @value: The value to store in the node.
 * Return: pointer, or NULL if fail.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *tree, *new, *current;
    int size, leaves, sub, bit, level, tmp;

    if (root == NULL)
        return NULL;
    if (!(*root))
        return (*root = binary_tree_node(NULL, value));

    tree = *root;
    size = binary_tree_size(tree);
    leaves = size;
    for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
        leaves -= sub;

    for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
        tree = leaves & bit ? tree->right : tree->left;

    new = binary_tree_node(tree, value);
    leaves & 1 ? (tree->right = new) : (tree->left = new);

    current = new;
    for (; current->parent && (current->n > current->parent->n); current = current->parent)
    {
        tmp = current->n;
        current->n = current->parent->n;
        current->parent->n = tmp;
        new = new->parent;
    }

    return new;
}

