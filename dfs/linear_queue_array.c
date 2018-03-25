/**
* Created on 02/03/2018
*
* Cheick Ali M. DIALLO
* contact@cheickalimdiallo.com
*
* Operations on a linear queue, implemented as an array.
*/
#include <stdio.h>

#define MAX 5

typedef struct
{
    short back;
    short count;
    short elements[MAX];
}
Queue;

void initialize(Queue *q)
{
    q->back = -1;
    q->count = 0;
}

short isFull(Queue *q)
{
    if (q->count == MAX)
        return 1;
    else
        return 0;
}

short isEmpty(Queue *q)
{
    if (q->count == 0)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, short e)
{
    if (!isFull(q))
    {
        q->elements[++q->back] = e;
        ++q->count;
        printf("%d enqueued\n", e);
    }
    else
        printf("Queue is full !\n");
}

void dequeue(Queue *q)
{
    if (!isEmpty(q))
    {
        printf("%d dequeued\n", q->elements[0]);
        --q->count;
        if (q->count > 1)
            for (short i = 1; i <= q->back; ++i)
                q->elements[i - 1] = q->elements[i];
        --q->back; 
    }
    else
        printf("Queue is empty !\n");
}

int main(void)
{
    Queue q;
    initialize(&q);
    dequeue(&q);
    enqueue(&q, 20);
    enqueue(&q, 6);
    enqueue(&q, 19);
    enqueue(&q, 3);
    enqueue(&q, 7);
    enqueue(&q, 35);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 35);
    enqueue(&q, 2);
    enqueue(&q, 64);
    enqueue(&q, 8);
}