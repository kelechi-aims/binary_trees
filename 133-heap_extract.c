#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;

    if (!tree)
        return 0;

    if (tree->left)
        left_height = 1 + tree_height(tree->left);

    if (tree->right)
        right_height = 1 + tree_height(tree->right);

    return (left_height > right_height) ? left_height : right_height;
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
    int swap_value;
    heap_t *tmp_parent, *tmp_child;

    if (!root)
        return;

    tmp_parent = root;

    while (1)
    {
        if (!tmp_parent->left)
            break;
        if (!tmp_parent->right)
            tmp_child = tmp_parent->left;
        else
        {
            tmp_child = (tmp_parent->left->n > tmp_parent->right->n) ? tmp_parent->left : tmp_parent->right;
        }
        if (tmp_parent->n > tmp_child->n)
            break;
        swap_value = tmp_parent->n;
        tmp_parent->n = tmp_child->n;
        tmp_child->n = swap_value;
        tmp_parent = tmp_child;
    }
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
    int extracted_value;
    heap_t *heap_root, *node;

    if (!root || !*root)
        return 0;

    heap_root = *root;
    extracted_value = heap_root->n;
    if (!heap_root->left && !heap_root->right)
    {
        *root = NULL;
        free(heap_root);
        return extracted_value;
    }

    _preorder(heap_root, &node, tree_height(heap_root));

    heap_root->n = node->n;
    if (node->parent->right)
        node->parent->right = NULL;
    else
        node->parent->left = NULL;
    free(node);
    heapify(heap_root);
    *root = heap_root;
    return extracted_value;
}

