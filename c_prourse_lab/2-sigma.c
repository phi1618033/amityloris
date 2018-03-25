/**
* sigma.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Adds the numbers 1 through n and returns the sum.
**/

#include <stdio.h>

int sigma(int n)
{
    // Base case.
    if(n < 2)
        return 1;
    else
        return n + sigma(n-1);
}

int main(void)
{
    // Prompts user for a natural number.
    int number;
    do
    {
        printf("Enter a natural number: ");
        scanf(" %i", &number);
    }
    while (number < 1);
    
    // Prints answer.
    printf("%i\n", sigma(number));
}