/**
* Created on 02/03/2018
*
* Cheick Ali M. DIALLO
* contact@cheickalimdiallo.com
*
* Operations on a linear queue, implemented as a linkedlist.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}
Node;

typedef struct
{
    int count;
    Node *first;
    Node *last;
}
Queue;

Queue *createQueue(void)
{
    Queue *q = calloc(sizeof(Queue), 1);
    q->count = 0;
    return q;
}

void enqueue(Queue *q, int value)
{
    Node *n = calloc(sizeof(Node), 1);
    if (!n)
    {
        printf("Queue is full !\n");
        return;
    }

    n->data = value;
    n->next = NULL;
    if (q->count == 0)
    {
        q->first = n;
        q->last = n;
    }
    else
    {
        q->last->next = n;
        q->last = n;
    }
    ++q->count;
    printf("%d enqueued\n", value);
}

void dequeue(Queue *q)
{
    if (q->count == 0)
    {
        printf("Queue is empty !\n");
        return;
    }

    int value = q->first->data;
    Node *n = q->first;
    q->first = n->next;
    n->next = NULL;
    free(n);
    --q->count;
    printf("%d dequeued\n", value);
}

int main(void)
{
    Queue *q = createQueue();
    dequeue(q);
    enqueue(q, 20);
    enqueue(q, 6);
    enqueue(q, 19);
    enqueue(q, 3);
    enqueue(q, 7);
    enqueue(q, 35);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 35);
    enqueue(q, 2);
    enqueue(q, 64);
    enqueue(q, 8);
}