/**
* Created on 02/03/2018
*
* Cheick Ali M. DIALLO
* contact@cheickalimdiallo.com
*
* Operations on a descending priority queue, implemented as an array.
*/
#include <stdio.h>

#define MAX 5

typedef struct
{
    short lowest_priority;
    short count;
    char elements[MAX];
}
Queue;

void initialize(Queue *q)
{
    q->lowest_priority = 0;
    q->count = 0;
    for (int i = 0; i < MAX; ++i)
        q->elements[i] = 0;
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

void enqueue(Queue *q, char e, short p)
{
    if (!isFull(q))
    {
        if (q->elements[p] == 0)
        {
            q->elements[p] = e;
            ++q->count;
            if (q->lowest_priority > p)
                q->lowest_priority = p;
            printf("%c enqueued\n", e);
        }
        else
        {
            printf("There is already an element with that priority !\n");
            return;
        }
    }
    else
        printf("Queue is full !\n");
}

void dequeue(Queue *q)
{
    if (!isEmpty(q))
    {
        char e;
        while ((e = q->elements[q->lowest_priority]) == 0)
            q->lowest_priority++;
        printf("%c dequeued\n", e);
        q->elements[q->lowest_priority] = 0;
        q->lowest_priority = 0;
        --q->count;
    }
    else
        printf("Queue is empty !\n");
}

int main(void)
{
    Queue q;
    initialize(&q);
    dequeue(&q);
    enqueue(&q, 'C', 3);
    enqueue(&q, 'V', 2);
    enqueue(&q, 'M', 0);
    enqueue(&q, 'C', 3);
    enqueue(&q, 'R', 1);
    enqueue(&q, 'S', 4);
    enqueue(&q, 'W', 2);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 'B', 0);
    enqueue(&q, 'D', 2);
    enqueue(&q, 'F', 4);
    enqueue(&q, 'K', 1);
}