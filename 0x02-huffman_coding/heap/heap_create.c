#include "heap.h"

/**
 * heap_create -  creates a Heap data structure
 * @data_cmp: pointer to a comparison function
 * Return: a pointer to the created heap_t structure, or NULL if it fails
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap;

	heap = malloc(sizeof(heap_t));
	if (!heap)
		return (NULL);
	heap->size = 0;
	heap->root = NULL;
	heap->data_cmp = data_cmp;
	return (heap);
}
