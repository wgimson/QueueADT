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

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: queue could not be created.\n");
    q->first = NULL;
    q->last = NULL;
    return q;
}

void destroy(Queue q)
{
    make_empty(q);
    free(q);
}

void make_empty(Queue q)
{
    while (!is_empty(q))
       queue_remove(q);
}

bool is_empty(Queue q)
{
    return (q->first == NULL); 
           
}

bool is_full(Queue q)
{
    return false;
}

void queue_insert(Queue q, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in insert: queue is full.\n");

    new_node->data = i;
    if (is_empty(q)) {
        new_node->next = new_node;
        q->first = q->last = new_node;
        return;
    }
    struct node *last_node = q->last;
    last_node->next = new_node;
    q->last = new_node;
}

Item queue_remove(Queue q)
{
    struct node *old_front;
    struct node *only_node;
    Item i;

    if (is_empty(q)) 
        terminate("Error in queue_remove(): queue empty.\n");

    if (q->first == q->last) {          /* one node in linked list */
        only_node = q->first;
        i = only_node->data;
        free(only_node);
        q->first = NULL;  /* if this line is omitted, throws 'glibc detected: double free' */
        return i;
    }
    old_front = q->first;
    q->first = old_front->next;
    i = old_front->data;
    free(old_front);
    return i;
}

Item peek_first(Queue q)
{
    struct node *first_node = q->first;
    return first_node->data;
}

Item peek_last(Queue q)
{
    struct node *last_node = q->last;
    return last_node->data;
}
