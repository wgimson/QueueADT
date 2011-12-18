#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>                /* C99 only */

typedef int Item;

typedef struct queue_type *Queue;

Queue create(void);
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void queue_insert(Queue q, Item i);
Item queue_remove(Queue q);
Item peek_first(Queue q);
Item peek_last(Queue q);

#endif
