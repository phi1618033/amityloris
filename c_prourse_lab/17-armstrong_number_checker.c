/**
* 17-armstrong_number_checker.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program checks whether a number is an Armstrong number.
* An armstrong number is a number that is the sum of its own digits each raised to the power of the number of digits.
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompts for a positive integer.
    int integer;
    do
    {
        printf("Enter a positive integer: ");
        scanf("%i", &integer);
    }
    while (integer < 1);

    // Counts the number of digits in the integer.
    int number_of_digits = (int)(log10(integer) + 1);

    /* Checks whether the integer is an armstrong number. */
    int sum, digit;
    sum = 0;
    digit = 0;
    for (int i = 1; i <= number_of_digits; i++)
    {
        // The ith digit is ((integer modulo 10^i) / 10^i-1).
        // Gets digit at position i.
        digit = (int)(integer % (int)pow(10, i)) / pow(10, i - 1);
        // Raises it to the power of the number of digits and Adds up.
        sum += pow(digit, number_of_digits);
    }
    
    if (sum == integer)
        printf("%i is an Armstrong number.", integer);
    else
        printf("%i is not an Armstrong number.", integer);
    printf("\n");
}