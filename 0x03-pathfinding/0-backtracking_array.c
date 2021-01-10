#include "pathfinding.h"

/**
 * backtracking_array -  searches for the first path from a starting point to
 * a target point within a two-dimensional array
 * @map: pointer to a read-only two-dimensional array
 * @rows: number of rows of @map
 * @cols: number of cols of @map
 * @start: stores the coordinates of the starting point
 * @target: stores the coordinates of the target point
 * Return: queue, in which each node is a point in the path from start
 * to target
 */
queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target)
{
	queue_t *queue = NULL;
	(void) map;
	(void) rows;
	(void) cols;
	(void) start;
	(void) target;

	queue = malloc(sizeof(queue_t));
	queue->back = NULL;
	queue->front = NULL;

	return (queue);
}
