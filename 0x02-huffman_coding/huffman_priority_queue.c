#include "huffman.h"
/**
* free_data - delete a set of structures
* @data: data to delete
* Return: Nothing
*/
void free_data(void *data)
{
	binary_tree_node_t *node = NULL;

	node = (binary_tree_node_t *) data;
	if (!node)
		return;
	if (node->data)
		free(node->data);
	free(node);
}

/**
* huffman_data_comparison - get the subtration of data1 - data2
* @data1: void pointer which store the data of the node1
* @data2: void pointer which store the data of the node2
* Return: the subtration of data1 - data2
*/
int huffman_data_comparison(void *data1, void *data2)
{
	size_t freq_1 = 0, freq_2 = 0;
	binary_tree_node_t *data_node1 = NULL, *data_node2 = NULL;

	data_node1 = (binary_tree_node_t *) data1;
	data_node2 = (binary_tree_node_t *) data2;

	if ((!data_node1 && data_node2) ||
		(data_node1 && !data_node1->data && data_node2 && data_node2->data))
		return (-1);
	else if ((data_node1 && !data_node2) ||
		(data_node1 && data_node1->data && data_node2 && !data_node2->data))
		return (1);
	else if ((!data_node1 && !data_node2) ||
		(data_node1 && !data_node1->data && data_node2 && !data_node2->data))
		return (0);

	freq_1 = ((symbol_t *)data_node1->data)->freq;
	freq_2 = ((symbol_t *)data_node2->data)->freq;

	return (freq_1 - freq_2);
}

/**
* huffman_priority_queue - creates a priority queue for the Huffman
* coding algorithm
* @data: array of characters of size size
* @freq: array containing the associated frequencies (of size size too)
* @size: lenght of the previous arrays
* Return: pointer to the created min heap (also called priority queue)
*/
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	size_t iterator = 0;
	symbol_t *new_symbol = NULL;
	heap_t *new_heap = NULL;
	binary_tree_node_t *new_node = NULL, *node_inserted = NULL;

	if (!data || !freq)
		return (NULL);

	new_heap = heap_create(huffman_data_comparison);
	if (!new_heap)
		return (NULL);

	for (iterator = 0; iterator < size; iterator++)
	{
		new_symbol = symbol_create(data[iterator], freq[iterator]);
		if (!new_symbol)
			return (heap_delete(new_heap, free_data), NULL);

		new_node = binary_tree_node(NULL, new_symbol);
		if (!new_node)
			return (free(new_symbol), heap_delete(new_heap, free_data), NULL);

		node_inserted = heap_insert(new_heap, (void *) new_node);
		if (!node_inserted)
			return (free_data(new_node), heap_delete(new_heap, free_data), NULL);
	}

	return (new_heap);
}