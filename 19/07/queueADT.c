// (b) Write a linked-list implementation of the queue module described in
// Exercise 1. Use two pointers, one pointing to the first node in the list and
// the other pointing to the last node. When an item is inserted into the queue,
// add it to the end of the list. When an item is removed from the queue, delete
// the first node in the list.#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
	Item data;
	struct node *next;
};

struct queue_type {
	struct node *first;
	struct node *last;
};

static void terminate(const char *message);

Queue queue_create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in queue_create: queue could not be created.");
	q->first = NULL;
	q->last = NULL;
	return q;
}

void queue_destroy(Queue q)
{
	queue_make_empty(q);
	free(q);
}

void queue_insert(Queue q, Item i)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL)	
		terminate("Error in queue_insert: node could not be created.");
	new_node->data = i;
	new_node->next = NULL;

	if (q->first == NULL)
		q->first = new_node;
	else
		q->last->next = new_node;
	q->last = new_node;
}

Item queue_remove(Queue q)
{
	if (queue_is_empty(q))	
		terminate("Error in queue_remove: queue is empty.");

	struct node *old_first = q->first;
	Item i = old_first->data;

	q->first = q->first->next;
	if (q->first == NULL)
		q->last = NULL;
	free(old_first);

	return i;
}

Item queue_get_first(Queue q)
{
	if (queue_is_empty(q))	
		terminate("Error in queue_get_first: queue is empty.");
	return q->first->data;
}

Item queue_get_last(Queue q)
{
	if (queue_is_empty(q))	
		terminate("Error in queue_get_last: queue is empty.");
	return q->last->data;
}

void queue_make_empty(Queue q)
{
	while (q->first != NULL) {
		struct node *temp = q->first;
		q->first = q->first->next;
		free(temp);
	}
	q->last = NULL;
}

bool queue_is_empty(Queue q)
{
	return q->first == NULL;
}

bool queue_is_full(Queue q)
{
	return false;
}

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}
