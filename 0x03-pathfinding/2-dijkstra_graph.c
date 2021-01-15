#include "pathfinding.h"

/**
 * get_vertex_index - A function that fetches an vertex existing in graph by
 * name
 * @graph: A pointer to the graph
 * @index: The index identifying the vertex
 * Return: vertex on success,  NULL on failure
 */
vertex_t *get_vertex_index(const graph_t *graph, size_t index)
{
	vertex_t *node;

	if (index > graph->nb_vertices)
		return (NULL);
	node = graph->vertices;
	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (node->index == index)
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * get_smallest - A function that fetches index of vertex with smallest
 * tentative distance among the nodes in the unsaw
 * @graph: A pointer to the graph
 * @dest:  The array to track the distances from start to a vertex
 * @v: The array to track if vertex is saw or not
 * @index: The index with minimun identifying the vertex with minimum
 * tentative distance
 *
 * Return: minimum tentative distance among the nodes in the unsaw
 */
size_t get_smallest(graph_t *graph, size_t *dest, size_t *v, size_t *index)
{
	size_t min = UINT_MAX;
	size_t *a = dest;
	size_t i = 0;

	while (i < graph->nb_vertices)
	{
		if (*a < min && v[i] == 1)
		{
			min = *a;
			*index = i;
		}
		a++;
		i++;
	}
	return (min);
}

/**
 * queue_charge - A function that charges the queue with the shortest path
 * @graph: A pointer to the graph
 * @queue: queue to be filled in
 * @parent: The array to track parents of vertices
 * @start: A pointer to the starting vertex
 * @target: A pointer to the target vertex
 *
 * Return: Nothing
 */
void queue_charge(graph_t *graph, queue_t *queue, char **parent,
	vertex_t const *start, vertex_t const *target)
{
	size_t i = 0, t = 0;
	vertex_t *v;

	t = target->index;
	if (parent[t])
	{
		queue_push_front(queue, strdup(target->content));
		while (strcmp(parent[t], start->content))
		{
			queue_push_front(queue, strdup(parent[t]));
			v = graph->vertices;
			for (i = 0; i < graph->nb_vertices && v; i++)
			{
				if (strcmp(v->content, parent[t]) == 0)
				{
					t = i;
					break;
				}
				v = v->next;
			}
		}
		queue_push_front(queue, strdup(start->content));
	}
}

/**
 * find_path - Uses dijkstra algorithm to find the path
 * @graph: pointer to the graph to go through
 * @saw: The array to track if vertex is saw or not
 * @parent: The array to track parents of vertices
 * @dest:  The array to track the distances from start to a vertex
 * @start: A pointer to the starting vertex
 * @target: A pointer to the target vertex
 * @index: index of a current vertex tracked
 */
void find_path(graph_t *graph, size_t *saw, char **parent,
	size_t *dest, const vertex_t *start, const vertex_t *target, size_t index)
{
	vertex_t *curr, *child;
	edge_t *edge;
	size_t smallest = UINT_MAX, alt;

	curr = get_vertex_index(graph, index);
	if (!curr)
		return;
	edge = curr->edges;
	printf("Checking %s, distance from %s is %ld\n", curr->content,
	       start->content, dest[index]);
	while (edge && saw[index] == 1)
	{
		child = edge->dest;
		alt = dest[index] + edge->weight;
		if (child && (dest[child->index] > alt))
		{
			dest[child->index] = dest[index] + edge->weight;
			if (parent[child->index])
			{
				free(parent[child->index]);
				parent[child->index] = NULL;
			}
			parent[child->index] = strdup(curr->content);
		}
		edge = edge->next;
	}
	saw[index] = 1;
	smallest = get_smallest(graph, dest, saw, &index);
	if (saw[target->index] == 1 || smallest == UINT_MAX)
		return;

	find_path(graph, saw, parent, dest, start, target,
		index);
}


/**
 * dijkstra_graph - searches for the shortest path from a starting point to a
 * target point in a graph.
 * @graph: pointer to the graph to go through
 * @start:pointer to the starting vertex
 * @target: pointer to the target vertex
 * Return: queue, in which each node is a char * corresponding to a vertex,
 * forming a path from start to target
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	queue_t *queue;
	size_t *dest, i, *saw;
	char **parent;

	if (graph != NULL)
	{
		queue = queue_create();
		saw = (size_t *)malloc(graph->nb_vertices * sizeof(size_t));
		parent = (char **)malloc(graph->nb_vertices * sizeof(char *));
		dest = (size_t *) malloc(graph->nb_vertices * sizeof(size_t));
		for (i = 0; i < graph->nb_vertices; i++)
		{
			dest[i] = UINT_MAX;
			saw[i] = 1;
			parent[i] = NULL;
		}
		dest[start->index] = 0;
		find_path(graph, saw, parent, dest, start, target,
				 start->index);
		queue_charge(graph, queue, parent, start, target);
		free(saw);
		free(dest);
		for (i = 0; i < graph->nb_vertices; i++)
		{
			free(parent[i]);
		}
		free(parent);
		if (!queue->front)
		{
			free(queue);
			queue = NULL;
		}
	}
	return (queue);
}
