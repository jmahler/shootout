
#include "tree.h"
#include "queue.h"

struct node* make_node(int val, struct node *left, struct node *right)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (!new_node) {
		perror("malloc node");
		return NULL;
	}
	new_node->val = val;
	new_node->left = left;
	new_node->right = right;

	return new_node;
}

void free_tree(struct node *n)
{
	if (n->left)
		free_tree(n->left);

	if (n->right)
		free_tree(n->right);

	free(n);
}

struct node *depth_first_search(struct node *n, int val)
{
	struct node *found;

	if (n == NULL)
		return NULL;

#ifdef VERBOSE
	printf("  node: %i (%p), match? %s\n",
				n->val, n, (n->val == val) ? "yes" : "no");
#endif

	if (n->val == val)
		return n;

	found = depth_first_search(n->left, val);
	if (found != NULL)
		return found;

	found = depth_first_search(n->right, val);
	if (found != NULL)
		return found;

	return NULL;
}

struct node *breadth_first_search(struct node *n, int val)
{
	struct queue q = {0};

	queue_push(&q, n);

	while ( (n = queue_shift(&q))) {

#ifdef VERBOSE
		printf("  node: %i (%p), match? %s\n",
				n->val, n, (n->val == val) ? "yes" : "no");
#endif

		if (n->val == val)
			break;

		if (n->left != NULL)
			queue_push(&q, n->left);

		if (n->right != NULL)
			queue_push(&q, n->right);
	}

	flush_queue(&q);

	return n;
}
