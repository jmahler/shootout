
#include "tree.h"

struct node* make_node(int val, ...)
{
	va_list ap;
	struct node *new_node;
	struct node **children;
	int i;
	int num_children;

	new_node = malloc(sizeof(struct node));
	if (!new_node) {
		perror("malloc node");
		return NULL;
	}
	new_node->val = val;

	/*
	 * first, count the number of child nodes
	 *
	 * NOTE: va_arg does not return NULL beyond the last value.
	 *   But since a NULL argument is given by convention,
	 *   it will return NULL as the last value.
	 */
	va_start(ap, val);
	for (num_children = 0; va_arg(ap, struct node *); num_children++) {};
	va_end(ap);

	/* then create a NULL terminated array of children */
	children = malloc((num_children + 1) * sizeof(struct node *));
	if (!children) {
		perror("malloc children");
		free(new_node);
		return NULL;
	}
	new_node->children = children;  /* save start */

	/* assign the children */
	va_start(ap, val);
	for (i = 0; i <= num_children; i++) {
		*children = va_arg(ap, struct node *);
		/* last child will be NULL by convention */
		children++;
	}
	va_end(ap);

	return new_node;
}

void free_tree(struct node *n)
{
	struct node **children = n->children;

	while (*children != NULL) {
		free_tree(*children);
		children++;
	}
	free(n->children);
	free(n);
}

struct node *depth_first_search(struct node *n, int val)
{
	struct node **child;

	printf("(%p) %i\n", n, n->val);  /* verbose output */

	if (n->val == val)
		return n;

	child = n->children;

	while (*child != NULL) {
		struct node *found;
		found = depth_first_search(*child, val);
		if (found != NULL)
			return found;
		child++;
	}

	return NULL;
}

struct node *breadth_first_search(struct node *n, int val)
{
	struct node **child;

	printf("(%p) %i\n", n, n->val);  /* verbose output */

	/* TODO */

	return NULL;
}
