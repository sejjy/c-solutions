// (a) Write an array-based implementation of the queue module described in
// Exercise 1. Use three integers to keep track of the queue’s status, with one
// integer storing the position of the first empty slot in the array (used when
// an item is inserted), the second storing the position of the next item to be
// removed, and the third storing the number of items in the queue. An insertion
// or removal that would cause either of the first two integers to be
// incremented past the end of the array should instead reset the variable to
// zero, thus causing it to “wrap around” to the beginning of the array.

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

struct queue_type {
	Item data[QUEUE_SIZE];
	int front;
	int back;
	int length;
};

static void terminate(const char *message);

Queue queue_create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in queue_create: queue could not be created.");
	q->front = 0;
	q->back = 0;
	q->length = 0;
	return q;
}

void queue_destroy(Queue q)
{
	free(q);
}

void queue_insert(Queue q, Item i)
{
	if (queue_is_full(q))	
		terminate("Error in queue_insert: queue is full.");
	q->data[q->back] = i;
	q->back = (q->back + 1) % QUEUE_SIZE;
	q->length++;
}

Item queue_remove(Queue q)
{
	if (queue_is_empty(q))	
		terminate("Error in queue_remove: queue is empty.");
	Item i = q->data[q->front];
	q->front = (q->front + 1) % QUEUE_SIZE;
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
	return q->data[(q->back - 1 + QUEUE_SIZE) % QUEUE_SIZE];
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
	return q->length == QUEUE_SIZE;
}

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

// queue_create:
//     [ ][ ][ ]   len: 0
//      0  1  2
//      fb
// queue_insert:
//     [#][ ][ ]   len: 1
//      0  1  2
//      f  b
// queue_insert:
//     [#][#][ ]   len: 2
//      0  1  2
//      f     b
// queue_remove:
//     [?][#][ ]   len: 1
//      0  1  2
//         f  b
