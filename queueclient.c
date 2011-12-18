#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

int main(void)
{
    Queue q1, q2;
    int n;

    q1 = create();
    q2 = create();

    queue_insert(q1, 1);
    queue_insert(q1, 2);

    n = peek_first(q1);
    printf("We peeked and %d is first in q1.\n", n);
    n = peek_last(q1);
    printf("We peeked and %d is last in q1.\n", n);

    n = queue_remove(q1);
    printf("Removed %d from q1.\n", n);
    queue_insert(q2, n);
    n = queue_remove(q1);
    printf("Removed %d from q1.\n", n);
    queue_insert(q2, n);

    destroy(q1);

    while (!is_empty(q2))
        printf("Removed %d from q2.\n", queue_remove(q2));

    queue_insert(q2, 3);

    n = peek_first(q2);
    printf("We peeked and %d is first in q2.\n", n);
    n = peek_last(q2);
    printf("We peeked and %d is last in q2.\n", n);
    
    make_empty(q2);
    if (is_empty(q2))
        printf("q2 is empty.\n");
    else 
        printf("q2 is not empty.\n");

    destroy(q2);

    return 0;
}
