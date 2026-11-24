// Starting from the queue.h header of Exercise 1, create a file named
// queueADT.h that defines the following Queue type:
//
// typedef struct queue_type *Queue;
//
// queue_type is an incomplete structure type. Create a file named queueADT.c
// that contains the full definition of queue_type as well as definitions for
// all the functions in queue.h. Use a fixed-length array to store the items in
// a queue (see Exercise 3(a)). Create a file named queueclient.c (similar to
// the stackclient.c file of Section 19.4) that creates two queues and performs
// operations on them. Be sure to provide create and destroy functions for your
// ADT.

#include <stdio.h>
#include "queueADT.h"

int main(void) {
	Queue q1, q2;
	int n;

	q1 = queue_create();
	q2 = queue_create();

	queue_insert(q1, 1);
	queue_insert(q1, 2);

	n = queue_remove(q1);
	printf("Removed %d from s1\n", n);
	queue_insert(q2, n);
	n = queue_remove(q1);
	printf("Removed %d from s1\n", n);
	queue_insert(q2, n);

	queue_destroy(q1);

	while (!queue_is_empty(q2))
		printf("Removed %d from s2\n", queue_remove(q2));

	queue_insert(q2, 3);
	queue_make_empty(q2);
	if (queue_is_empty(q2))
		printf("s2 is empty\n");
	else
		printf("s2 is not empty\n");

	queue_destroy(q2);

	return 0;
}
