#include "graphs.h"
/**
 * graph_create - A function that allocates memory to store a graph_t
 * Return: A pointer to the allocated structure, or NULL on failure
 */
graph_t *graph_create(void)
{
	graph_t *newgraph = NULL;

	newgraph = malloc(sizeof(graph_t));

	if (newgraph == NULL)
		return (NULL);

	newgraph->nb_vertices = 0;
	newgraph->vertices = NULL;

	return (newgraph);
}
