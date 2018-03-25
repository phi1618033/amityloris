/**
* 22-bubble_sorting_number_array.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program sorts a given array of numbers using Bubble sort.
*/
#include <stdio.h>

#define ARRAY_SIZE 5

int main(void)
{
    // Sets array values.
    float array[ARRAY_SIZE] = {15.0, 58.3, -96.2, 45, -14.3};

    // Sorts array in ascending order using bubble sort.
    float temp;
    for (int i = 0; i < ARRAY_SIZE - 1; i++)
    {
        for (int j = 0; j < ARRAY_SIZE - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Prints sorted array.
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf(" %2.f", array[i]);
    }
    printf("\n");
}