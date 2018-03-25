/**
* 32-recursive_fibonacci.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program generates n fibonacci numbers using recursion.
* In the fibonacci sequence, every number after the first two is the sum of the two preceding ones.
*/
#include <stdio.h>

// The function is called in the following manner: print_fibonacci(0, 1, 0, count, 0);
void print_fibonacci(unsigned long long last_but_one, unsigned long long last, unsigned long long fibonacci, unsigned long long count, unsigned long long i)
{
    if (i == count)
    {
        printf("\n");
        return;
    }
    else
    {
        last_but_one = last;
        last = fibonacci;
        fibonacci = last + last_but_one;
        printf(" %llu", fibonacci);
        print_fibonacci(last_but_one, last, fibonacci, count, i + 1);
    }
}

int main(void)
{
    // Prompts for a non-negative integer.
    long long count = 0;
    do
    {
        printf("Enter a positive integer: ");
        scanf("%lld", &count);
    }
    while (count < 1);

    // Prints the fibonacci number sequence up to that integer.
    print_fibonacci(0, 1, 0, count, 0);
}