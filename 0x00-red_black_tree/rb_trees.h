#ifndef _RB_TREES_H_
#define _RB_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#define moveRed(sibling) \
	((sibling->left && \
	sibling->left == RED) || \
	(sibling->right && \
	sibling->right == RED))
#define moveBlack(node, succesor) \
	((succesor == NULL || \
	succesor->color == BLACK) && \
	(node->color == BLACK))
#define GetP(node) ((node == NULL) ? NULL : node->parent)
#define GetGP(node) GetP(GetP(node))
#define GetS(node) \
	(GetP(node) ? \
	((node == (GetP(node)->left)) ? \
	(GetP(node)->right) : \
	(GetP(node)->left)) : \
	NULL)
#define GetU(node) GetS(GetP(node))

/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 * @DOUBLE_BLACK: 2 -> Double-black node (used for deletion)
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);
int CheckColors(rb_tree_t *tree, int prev_color, int num_black,
	int num_black_path);
int rb_tree_is_valid(const rb_tree_t *tree);
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
rb_tree_t *array_to_rb_tree(int *array, size_t size);
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n);
rb_tree_t *insert_r(rb_tree_t *root, int value);
void rotate(rb_tree_t *node, int sense);
void fix_tree(rb_tree_t *node);
rb_tree_t *_succesor(rb_tree_t *node);
rb_tree_t *sValue(rb_tree_t *root, int n);
void move_red(rb_tree_t *sibling, rb_tree_t *parent);
// rb_tree_t *delete(rb_tree_t *node);

#endif /* _RB_TREES_H_ */
