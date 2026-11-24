// Modify Programming Project 5 so that the items in a queue are stored in a
// dynamically allocated array whose length is passed to the create function.

#include <stdio.h>
#include "queueADT.h"

int main(void) {
	Queue q1, q2;
	int n;

	q1 = queue_create(100);
	q2 = queue_create(200);

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
