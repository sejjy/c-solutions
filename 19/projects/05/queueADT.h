// A queue is similar to a stack, except that items are added at one end but
// removed from the other in a FIFO (first-in, first-out) fashion. Operations on
// a queue might include:
//
//     Inserting an item at the end of the queue
//     Removing an item from the beginning of the queue
//     Returning the first item in the queue (without changing the queue)
//     Returning the last item in the queue (without changing the queue)
//     Testing whether the queue is empty
//
// Write an interface for a queue module in the form of a header file named
// queue.h.

#ifndef QUEUE_ADT_H
#define QUEUE_ADT_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue queue_create(void);
void queue_destroy(Queue q);
void queue_insert(Queue q, Item i);
Item queue_remove(Queue q);
Item queue_get_first(Queue q);
Item queue_get_last(Queue q);
void queue_make_empty(Queue q);
bool queue_is_empty(Queue q);
bool queue_is_full(Queue q);

#endif /* QUEUE_ADT_H */
