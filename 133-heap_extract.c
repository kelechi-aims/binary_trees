#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_down - Restores the max-heap property starting from root
 * @root: Pointer to the root node of the heap
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
        int temp = root->n;
        root->n = largest->n;
        largest->n = temp;
        heapify_down(largest);
    }
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Double pointer to the heap root
 * Return: Value of extracted node or 0 if failed
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return (0);

    int extracted_value = (*root)->n;
    heap_t *last_node = *root;
    heap_t *parent = NULL;

    while (last_node->right)
    {
        parent = last_node;
        last_node = last_node->right;
    }

    if (last_node == *root)
    {
        free(*root);
        *root = NULL;
        return (extracted_value);
    }

    (*root)->n = last_node->n;

    if (parent->right)
        parent->right = NULL;
    else
        parent->left = NULL;

    free(last_node);
    heapify_down(*root);
    return (extracted_value);
}
