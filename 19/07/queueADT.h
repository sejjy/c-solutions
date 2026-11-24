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
