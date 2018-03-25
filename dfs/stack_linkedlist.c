/**
* stack_linkedlist.c
*
* Cheick Ali M. DIALLO
* contact@cheickalimdiallo.com
*
* Operations on a stack, implemented as a linked list.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define FALSE 0
#define TRUE 1

typedef unsigned short Bool;

typedef struct node
{
    short data;
    struct node* next;
}
Node;

void push(Node** N, short value)
{
    // Creates new node.
    Node* new = (Node*)malloc(sizeof(Node));
    // Checks if stack is full.
    if (!new)
    {
        printf("Stack is full !\n");
        return;
    }

    // Insert value.
    new->data = value;
    // Checks if it is the first value in the stack.
    if (*N == NULL)
    {
        new->next = NULL;
        *N = new;
    }
    else
    {
        // Add current value as the last value.
        new->next = *N;
        *N = new;
    }
    printf("%d pushed\n", (*N)->data);
}

void pop(Node** N)
{
    // Checks if the stack is empty.
    if (*N == NULL)
    {
        printf("Stack is empty !\n");
        return;
    }

    // Make the last but one value the last value and remove the last value.
    Node* last = *N;
    *N = last->next;
    printf("%d popped\n", last->data);
    free(last);
}

void empty(Node** N)
{
    // Checks if the stack is empty.
    if (!(*N))
    {
        printf("Stack is empty !\n");
        return;
    }

    // Goes down the stack and removes all elements in it.
    Node* n = *N;
    Node* temp;
    while (n != NULL)
    {
        temp = n;
        n = n->next;
        free(temp);
    }
    *N = NULL;
}

int main(void)
{
    Node* S = NULL;
    empty(&S);
    pop(&S);
    push(&S, 35);
    push(&S, 58);
    push(&S, 85);
    push(&S, 50);
    push(&S, 13);
    push(&S, 30);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    push(&S, 50);
    empty(&S);
    pop(&S);
}