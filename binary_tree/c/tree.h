#ifndef TREE_H
#define TREE_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *left;
	struct node *right;
};

/*
 * Make a new node and build a tree.
 *
 * struct node *node_1 = make_node(1, NULL, NULL);
 * struct node *node_7 = make_node(7, NULL, NULL);
 * struct node *node_5 = make_node(5, node_1, node_7);
 *
 *     5
 *    / \
 *   1   7
 */
struct node *make_node(int val, struct node *left, struct node *right);

/*
 * Free a tree structure and all of its children.
 *
 *   free_tree(root_node);
 */
void free_tree(struct node *);

/*
 * Perform a depth first search to find the node with the value.
 *
 *   struct node *found;
 *
 *   found = depth_first_search(root, 12);
 */
struct node *depth_first_search(struct node *root, int val);

/*
 * Perform a breadth first search to find the node with the value.
 *
 *   struct node *found;
 *
 *   found = breadth_first_search(root, 12);
 */
struct node *breadth_first_search(struct node *root, int val);

#endif /* TREE_H */
