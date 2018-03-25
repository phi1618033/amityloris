/**
* 13-looping_fibonacci.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program generates a fibonacci number sequence up to an integer n using a loop.
* In the fibonacci sequence, every number after the first two is the sum of the two preceding ones.
*/
#include <stdio.h>

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
    int fibonacci, last_but_one, last;
    fibonacci = 0;
    last_but_one = 0;
    last = 1;
    while (fibonacci <= integer)
    {
        printf(" %i", fibonacci);
        last_but_one = last;
        last = fibonacci;
        fibonacci = last + last_but_one;
    }
    printf("\n");
}