/**
* recursive_factorial.c
*
* DIALLO CHEICK ALI MOUSSA
* Bachelor of Computer Applications
* A1922517022(el)
* diallo.c@valorisuniversity.com
* 
*
* The program computes the factorial of a number using recursion.
*/
#include <stdio.h>

long long factorial(long long n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
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