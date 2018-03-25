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

unsigned short sum_of_digits_(unsigned int positive_integer)
{

    // Gets the number of digits in the positive integer.
    unsigned int digit_count = (unsigned int)log10(positive_integer) + 1;

    // Add up each number in the positive integer.
    unsigned short sum = 0;
    for (unsigned short i = 1; i <= digit_count; i++)
    {
        // The ith digit is ((positive_integer modulo 10 to the power of i) / 10 to the power of i - 1).
        sum += (unsigned short)((positive_integer % (unsigned int)pow(10, i)) / pow(10, i - 1));
    }
    return sum;
}

unsigned short sum_of_digits(unsigned int positive_integer, unsigned short digit_count, unsigned short i)
{

    if (i > digit_count)
        return 0;
    else
    {
        unsigned short current_digit = (unsigned short)((positive_integer % (unsigned int)pow(10, i)) / pow(10, i - 1));
        return current_digit + sum_of_digits(positive_integer, digit_count, i + 1);
    }
}

int main(void)
{
    // Prompts for an integer.
    int integer = 0;
    do
    {
        printf("Enter a positive integer <= 5 digits: ");
        scanf("%u", &integer);
    } 
    while (integer < 0);

    // Gets the number of digits in the positive integer.
    unsigned int digit_count = (unsigned int)log10(integer) + 1;

    // Add up each number in the integer.
    unsigned short sum = sum_of_digits(integer, digit_count, 1);

    // Prints the sum.
    printf("The sum of the digits are %i\n", sum);
}