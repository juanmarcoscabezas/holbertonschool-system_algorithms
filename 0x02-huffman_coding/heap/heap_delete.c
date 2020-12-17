#include "heap.h"

/**
* remove_heap - Removes all
* @root: pointer to the heap to delete
* @free_data: pointer to a function that will be used to free the content of a node
* Return:
*/
void remove_heap(binary_tree_node_t *root, void (*free_data)(void *))
{
	if (root)
	{
		remove_heap(root->left, free_data);
		remove_heap(root->right, free_data);
		if (free_data)
			free_data(root->data);
		free(root);
	}
}

/**
 * heap_delete - deallocates a heap
 * @heap: pointer to the heap to delete
 * @free_data: pointer to a function that will be used to free the content of a node
 * Return:
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (heap)
	{
		if (heap->root)
			remove_heap(heap->root, free_data);
		free(heap);
	}
}
