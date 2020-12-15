#include "heap.h"

/**
 * binary_tree_node - creates a generic Binary Tree node
 * @parent: pointer to the parent node of the node to be created
 * @data: data to be stored in the node
 * Return: a pointer to the created node or NULL if it fails
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new_node;

	new_node = malloc(sizeof(binary_tree_node_t));
	if (!new_node)
		return (NULL);
	new_node->parent = parent;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
