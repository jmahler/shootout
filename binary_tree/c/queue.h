#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

struct queue_node {
	void *data;
	struct queue_node *next;
};

struct queue {
	struct queue_node *start;
	struct queue_node *end;
};

struct queue *queue_push(struct queue *q, void *data);

void *queue_shift(struct queue *q);

void flush_queue(struct queue *q);

#endif /* QUEUE_H */
