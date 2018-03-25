/**
* 9-squaredma.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program computes the sum of squares of n natural numbers.
*/
#include <stdio.h>

int main(void)
{
    // Prompts for the natural number n.
    int n = 0;
    do
    {
        printf("Enter a natural number: ");
        scanf(" %i", &n);
    }
    while (n < 1);

    // Computes the sum of square of numbers from 1 through n;
    int sum = 0;
    while (n > 0)
    {
        sum += (n * n);
        n--;
    }

    // Prints the sum.
    printf("%i\n", sum);
}