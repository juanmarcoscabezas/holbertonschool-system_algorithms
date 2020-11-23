#include "graphs.h"
/**
 * graph_create - A function that allocates memory to store a graph_t
 * Return: A pointer to the allocated structure, or NULL on failure
 */
graph_t *graph_create(void)
{
	graph_t *graph = NULL;

	graph = malloc(sizeof(graph_t));

	if (graph == NULL)
		return (NULL);
	graph->nb_vertices = 0;
	graph->vertices = NULL;
	return (graph);
}