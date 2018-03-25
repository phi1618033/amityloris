/**
* 32-recursive_fibonacci.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program generates a fibonacci number sequence up to an integer n using recursion.
* In the fibonacci sequence, every number after the first two is the sum of the two preceding ones.
*/
#include <stdio.h>

void print_fibonacci(int last_but_one, int last, int fibonacci, long long number)
{
    if (fibonacci > number)
    {
        printf("\n");
        return;
    }
    else
    {
        printf(" %i", fibonacci);
        last_but_one = last;
        last = fibonacci;
        fibonacci = last + last_but_one;
        print_fibonacci(last_but_one, last, fibonacci, number);
    }
}

int main(void)
{
    // Prompts for a non-negative integer.
    long long integer = 0;
    do
    {
        printf("Enter a non-negative integer: ");
        scanf("%lld", &integer);
    }
    while (integer < 0);

    // Prints the fibonacci number sequence up to that integer.
    print_fibonacci(1, 1, 1, integer);
}