/**
* 20-extremes_array_numbers.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program finds the maximum and minimum number in a given array.
*/
#include <stdio.h>

#define ARRAY_SIZE 5

int main(void)
{
    // Prompts user for array values.
    float array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Enter a number : ");
        scanf(" %f", &array[i]);
    }

    // Finds the maximum and minimum number in the array.
    float max, min;
    max = array[0];
    min = array[0];
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        if (array[i] > max)
            max = array[i];
        else if (array[i] < min)
            min = array[i];
        else
            continue;
    }

    // Prints the maximum and minimum number.
    printf("Maximum is %.2f and minimum is %.2f\n", max, min);
}