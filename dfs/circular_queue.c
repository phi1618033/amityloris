/**
* Created on 02/03/2018
*
* Cheick Ali M. DIALLO
* contact@cheickalimdiallo.com
*
* Operations on a circular queue, implemented as an array.
*/
#include <stdio.h>

#define MAX 10

typedef struct
{
    short front;
    short rear;
    short count;
    short elements[MAX];
}
Queue;

void initialize(Queue *q)
{
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

short isFull(Queue *q)
{
    if (q->count > MAX-1)
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
        short i = q->rear % MAX;
        q->elements[i] = e;
        ++q->count;
        ++q->rear;
        printf("%d enqueued\n", e);
    }
    else
        printf("Queue is full !\n");
}

void dequeue(Queue *q)
{
    if (!isEmpty(q))
    {
        short i = q->front % MAX;
        printf("%d dequeued\n", q->elements[i]);
        --q->count;
        ++q->front;
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
    printf("count is %d, front is %d, rear is %d\n", q.count, q.front, q.rear);
}