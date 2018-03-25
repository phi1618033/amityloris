/**
* stack_array.c
*
* Cheick Ali M. DIALLO
* contact@cheickalimdiallo.com
*
* Operations on a stack, implemented as an array.
*/
#include <stdio.h>

#define MAX 5
#define FALSE 0
#define TRUE 1

typedef unsigned short Bool;

typedef struct
{
    short top;
    short list[MAX];
}
Stack;

Bool isFull(Stack *S)
{
    if (S->top == MAX - 1)
        return TRUE;
    else
        return FALSE;
}

Bool isEmpty(Stack *S)
{
    if (S->top == -1)
        return TRUE;
    else
        return FALSE;
}

void init(Stack *S)
{
    S->top = -1;
    printf("Stack initialized !\n");
}

void push(Stack *S, short value)
{
    // Checks for overflow.
    if (isFull(S))
    {
        printf("Stack is full !\n");
        return;
    }
    // Level up top.
    ++S->top;
    // Insert value.
    S->list[S->top] = value;
    printf("%d pushed\n", value);
}

void pop(Stack *S)
{
    // Checks for underflow.
    if (isEmpty(S))
    {
        printf("Stack is empty !\n");
        return;
    }

    printf("%d popped\n", S->list[S->top]);
    --S->top;
}

int main(void)
{
    Stack s;
    
    init(&s);
    pop(&s);
    push(&s, 7);
    push(&s, -96);
    push(&s, 12);
    push(&s, 5);
    push(&s, -74);
    push(&s, 43);
    pop(&s);
    pop(&s);
}