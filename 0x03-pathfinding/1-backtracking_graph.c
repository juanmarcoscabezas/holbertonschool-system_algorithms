#include "pathfinding.h"

/**
 * graph_fill - traverse graph until target found
 * @new_node: new_node to fill
 * @saw: array specifying if vertex has been saw
 * @current: Current node
 * @target: Target to make the search
 * Return: The new string from start to target, otherwise NULL
 */
queue_node_t *graph_fill(queue_t *new_node, int *saw, const vertex_t *current,
	char *target)
{
	edge_t *e;

	if (current == NULL || saw[current->index] == 1)
		return (NULL);
	printf("Checking %s\n", current->content);
	if (!strcmp(current->content, target))
		return (queue_push_front(new_node, strdup(current->content)));
	saw[current->index] = 1;
	for (e = current->edges; e != NULL; e = e->next)
		if (graph_fill(new_node, saw, e->dest, target))
			return (queue_push_front(new_node, strdup(current->content)));
	return (NULL);
}

/**
 * backtracking_graph - searches for the first path from a starting point to
 * a target point in a graph.
 * @graph: pointer to the graph to go through
 * @start: pointer to the starting vertex
 * @target: pointer to the target vertex
 * Return: queue, in which each node is a char * corresponding to a vertex,
 * forming a path from start to target
 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	queue_t *new_node;
	int *saw;

	if (!graph || !start || !target)
		return (NULL);
	new_node = queue_create();
	if (new_node == NULL)
		return (NULL);
	saw = calloc(graph->nb_vertices, sizeof(*saw));
	if (saw == NULL)
		return (NULL);
	if (graph_fill(new_node, saw, start, target->content) == NULL)
	{
		queue_delete(new_node);
		new_node = NULL;
	}
	free(saw);
	return (new_node);
}
