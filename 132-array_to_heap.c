#include "binary_trees.h"

/**
 * array_to_heap -  function that builds a Max Binary Heap tree from an array
 * @array: array pointer
 * @size: The number of elements
 * Return: root, or NULL
 */
heap_t *array_to_heap(int *array, size_t size)
{
    if (!array || size == 0)
        return NULL;

    heap_t *root = heap_insert(NULL, array[0]);
    
    for (size_t a = 1; a < size; a++)
        heap_insert(&root, array[a]);

    return root;
}
