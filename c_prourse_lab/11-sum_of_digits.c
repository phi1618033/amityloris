/**
* 11-sum_of_digits.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program computes the sum of the digits of a given number.
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompts for an integer.
    int integer = -1;
    do
    {
        printf("Enter an non-negative integer: ");
        scanf("%i", &integer);
    }
    while (integer < 0);

    // Gets the number of digits in the integer.
    int number_of_digits = (int)(log10(integer)) + 1;
    printf("integer = %i, number of digits = %i\n", integer, number_of_digits);

    // Add up each number in the integer.
    int sum;
    sum = 0;
    for (int i = 1; i <= number_of_digits; i++)
    {
        // The ith digit is ((integer modulo 10^i) / 10^i-1)
        sum += (int)(integer % (int)pow(10, i)) / pow(10, i - 1);
        printf("sum = %i\n", sum);
    }

    // Prints the sum.
    printf("The sum of the digits are %i\n", sum);
}