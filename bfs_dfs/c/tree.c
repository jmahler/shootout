
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

	printf("  node: %i (%p), match? ", n->val, n);  /* verbose output */

	if (n->val == val) {
		printf("yes\n");
		return n;
	} else {
		printf("no\n");
	}

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

/*
 * The breadth first search algorithm here is not a typical one.  It
 * does not use a stack or queue or malloc.  Instead it uses a "depth".
 * Starting from the root a recursive search is performed at a specific
 * depth.  If no match is found, the next depth can be tried, and it
 * will start from the root again.
 *
 * More analysis is needed to determine whether this algorithm is
 * good or bad.  It does have to traverse nodes multiple times but
 * there is very little computation involved.
 *
 * It would be interesting to compare this to a traditional style bfs.
 */

/*
 * The maximum depth is discovered as the bfs proceeds by testing
 * whether there are more children.
 */
int max_depth;

static struct node *bfs_at_depth(struct node *n, int val,
				int depth, int cur_depth)
{
	if (cur_depth == depth) {
		printf("  node: %i (%p), match? ", n->val, n);

		if (n->val == val) {
			printf("yes\n");
			return n;
		} else {
			printf("no\n");

			if ((max_depth == depth) && n->children) {
				max_depth++;
			}

			return NULL;
		}
	} else if (cur_depth < depth) {
		struct node **child;

		printf("  node: %i (%p), step, depth=%i/%i\n", n->val, n,
							cur_depth + 1, depth);

		child = n->children;

		while (*child != NULL) {
			struct node *found;

			found = bfs_at_depth(*child, val, depth, cur_depth + 1);
			if (found != NULL)
				return found;
			child++;
		}
	}

	return NULL;
}

struct node *breadth_first_search(struct node *n, int val)
{
	struct node *found;
	int depth;

	depth = 0;
	max_depth = 0;
	while (1) {
		found = bfs_at_depth(n, val, depth, 0);
		if (found)
			break;

		if (depth == max_depth)
			break;

		depth++;
	}

	return found;
}
