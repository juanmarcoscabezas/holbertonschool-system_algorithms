#ifndef _PATHFINDING_
#define _PATHFINDING_

#include <stdlib.h>
#include <stdio.h>
#include "graphs.h"
#include "queues.h"
#include "string.h"
#include <limits.h>


#define RIGHT {1, 0}
#define BOTTOM {0, 1}
#define LEFT {-1, 0}
#define TOP {0, -1}

#define UNEXP '0'
#define EXP '1'
#define TRACK '2'
#define INFIN  UINT_MAX
#define NBVERTICES graph->nb_vertices
#define VERTICES graph->vertices

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);

#endif
