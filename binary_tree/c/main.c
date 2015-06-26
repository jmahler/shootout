
#include "tree.h"

int main() {
	struct node *root;
	struct node *found;
	int search_val;

	/*
	 * construct a tree
	 *
	 *        1
	 *       / \
	 *      2   5
	 *     / \   \
	 *    3   6   7
	 */
	root = make_node(1,
			make_node(2,
				make_node(3, NULL, NULL),
				make_node(6, NULL, NULL)),
			make_node(5, NULL,
				make_node(7, NULL, NULL)));

	search_val = 7;
	printf("depth first search for: %i\n", search_val);
	found = depth_first_search(root, search_val);
	if (found)
		printf("node found\n");
	else
		printf("node not found\n");

	search_val = 7;
	printf("breadth first search for: %i\n", search_val);
	found = breadth_first_search(root, search_val);
	if (found)
		printf("node found\n");
	else
		printf("node not found\n");

	free_tree(root);

	return 0;
}
