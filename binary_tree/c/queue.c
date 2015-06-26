
#include "queue.h"

struct queue *queue_push(struct queue *q, void *data)
{
	struct queue_node *new_end;
	struct queue_node *old_end;

	new_end = malloc(sizeof(*new_end));
	if (!new_end)
		return NULL;
	new_end->data = data;

	old_end = q->end;

	if (old_end == NULL) {
		q->start = new_end;
		q->end = new_end;
	} else {
		old_end->next = new_end;
		q->end = new_end;
	}

	return q;
}

void *queue_shift(struct queue *q)
{
	struct queue_node *old_start;
	void *data;

	old_start = q->start;

	if (old_start == NULL)
		return NULL;

	data = old_start->data;

	q->start = old_start->next;
	if (q->start == NULL)
		q->end = NULL;

	free(old_start);

	return data;
}

void flush_queue(struct queue *q)
{
	while (queue_shift(q)) {};
}
