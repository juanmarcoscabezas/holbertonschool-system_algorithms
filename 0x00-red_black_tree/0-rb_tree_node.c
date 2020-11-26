#include "rb_trees.h"
/**
* rb_tree_node -  creates a Red-Black Tree node
* @parent: Parent
* @value: New node value
* @color: Node Color
* Return: A new_node node on success, NULL otherwise
*/
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new_node = NULL;

	new_node = malloc(sizeof(rb_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->color = color;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
