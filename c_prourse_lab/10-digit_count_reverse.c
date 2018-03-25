/**
* 10-digit_count_reverse.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program counts the number of digits in a number and reverses them.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 13

int main(void)
{
    // Prompts for an integer.
    int integer = 0;
    do
    {
        printf("Enter an integer (less than 12 digits): ");
        scanf("%i", &integer);
    }
    while (integer < 0);

    // Gets the integer and store it as a string.
    char* number = calloc(MAX, sizeof(char));
    snprintf(number, MAX, "%i", integer);

    // Counts the number of digits in the string.
    int number_of_digits = strlen(number);

    // Reverses the digits in the string.
    char* reversed_number = calloc(number_of_digits + 1, sizeof(char));
    for (int i = number_of_digits - 1, j = 0; i > -1; i--, j++)
        *(reversed_number + j) = *(number + i);

    // Prints the counts and the number with reversed digits.
    printf("Reversed number is %s with %d digit(s)\n", reversed_number, number_of_digits);

    // Mess cleaning.
    free(number);
    free(reversed_number);
}