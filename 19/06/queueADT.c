#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type {
	Item *data;
	int front;
	int back;
	int length;
	int size;
};

static void terminate(const char *message);

Queue queue_create(int size)
{
	if (size <= 0)
		terminate("Error in queue_create: invalid queue size.");

	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in queue_create: queue could not be created.");

	q->data = malloc(size * sizeof(Item));
	if (q->data == NULL) {
		free(q);
		terminate("Error in queue_create: queue could not be created.");
	}

	q->front = 0;
	q->back = 0;
	q->length = 0;
	q->size = size;
	return q;
}

void queue_destroy(Queue q)
{
	free(q->data);
	free(q);
}

void queue_insert(Queue q, Item i)
{
	if (queue_is_full(q))	
		terminate("Error in queue_insert: queue is full.");
	q->data[q->back] = i;
	q->back = (q->back + 1) % q->size;
	q->length++;
}

Item queue_remove(Queue q)
{
	if (queue_is_empty(q))	
		terminate("Error in queue_remove: queue is empty.");
	Item i = q->data[q->front];
	q->front = (q->front + 1) % q->size;
	q->length--;
	return i;
}

Item queue_get_first(Queue q)
{
	if (queue_is_empty(q))	
		terminate("Error in queue_get_first: queue is empty.");
	return q->data[q->front];
}

Item queue_get_last(Queue q)
{
	if (queue_is_empty(q))	
		terminate("Error in queue_get_last: queue is empty.");
	return q->data[(q->back - 1 + q->size) % q->size];
}

void queue_make_empty(Queue q)
{
	q->front = 0;
	q->back = 0;
	q->length = 0;
}

bool queue_is_empty(Queue q)
{
	return q->length == 0;
}

bool queue_is_full(Queue q)
{
	return q->length == q->size;
}

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}
