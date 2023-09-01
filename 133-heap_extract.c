#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - swaps the values of two nodes
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * heapify_down - restores the max heap property from the root downwards
 * @root: pointer to the root of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *largest = root;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left && left->n > largest->n)
        largest = left;

    if (right && right->n > largest->n)
        largest = right;

    if (largest != root)
    {
        swap_values(root, largest);
        heapify_down(largest);
    }
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: double pointer to the heap root
 * Return: value of extracted node or 0 if failed
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return (0);

    int extracted_value = (*root)->n;
    heap_t *last_node = NULL;

    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (extracted_value);
    }

    last_node = *root;
    while (last_node->right)
        last_node = last_node->right;

    (*root)->n = last_node->n;

    if (last_node->parent->right)
        last_node->parent->right = NULL;
    else
        last_node->parent->left = NULL;

    free(last_node);
    heapify_down(*root);
    return (extracted_value);
}

