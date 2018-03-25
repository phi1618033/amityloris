/**
* 12-looping_factorial.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program computes the factorial of a given positive integer using a loop.
*/
#include <stdio.h>

long long factorial(long long n)
{
    // Starts by the number.
    long long result = n;
    // Multiply following numbers in decreasing order.
    for (long long i = n - 1; i > 1; i--)
        result *= i;
    return result;
}

int main(void)
{
    // Prompts for a positive integer.
    long long integer = 0;
    do
    {
        printf("Enter a positive integer between 1 and 19 included: ");
        scanf("%lld", &integer);
    }
    while (integer < 1 && integer > 20);

    // Computes its factorial.
    long long n = factorial(integer);

    // Prints the computed factorial.
    printf("The factorial is %lld\n", n);
}