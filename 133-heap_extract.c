#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_down - Repair the heap whose root element is at index 'root'
 * @root: The root of the binary heap
 */
void heapify_down(heap_t *root)
{
    while (1)
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
            root = largest;
        }
        else
        {
            break;
        }
    }
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node or 0 on failure
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return 0;

    int extracted_value = (*root)->n;
    heap_t *last_node = *root;

    while (last_node->left || last_node->right)
    {
        if (!last_node->right || last_node->left->n >= last_node->right->n)
            last_node = last_node->left;
        else
            last_node = last_node->right;
    }

    if (last_node == *root)
    {
        free(*root);
        *root = NULL;
        return extracted_value;
    }

    (*root)->n = last_node->n;

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);
    heapify_down(*root);

    return extracted_value;
}

