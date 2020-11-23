#include "graphs.h"
/**
 * graph_add_vertex - Adds a new vertex to a graph
 * @graph: Graph
 * @str: New vertes str
 * Return: a vertex pointer on succes or NULL
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t  *vertex = NULL, *v_head = NULL;
	char *new_str = NULL;
	unsigned int len = 0;

	if (str == NULL || graph == NULL)
		return (NULL);
	v_head = graph->vertices;
	while (v_head)
	{
		if (strcmp(str, v_head->content) == 0)
			return (NULL);
		if (v_head->next)
			v_head = v_head->next;
		else
			break;
	}
	vertex = malloc(sizeof(vertex_t));
	if (vertex == NULL)
		return (NULL);
	len = strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
	{
		free(vertex);
		return (NULL);
	}
	vertex->content = strcpy(new_str, str);
	vertex->index = graph->nb_vertices;
	vertex->nb_edges = 0, vertex->edges = NULL;

	if (!vertex)
		return (NULL);

	if (v_head)
		v_head->next = vertex;
	else
		graph->vertices = vertex;

	graph->nb_vertices++;
	return (vertex);
}
