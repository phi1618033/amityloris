/**
* 23-one_dim_array_concat.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program concatenates two one-dimensional arrays.
*/
#include <stdio.h>

#define ARRAY_SIZE 5

int main(void)
{
    // Sets arrays values.
    float a1[ARRAY_SIZE] = {15.0, 58.3, -96.2, 45, -14.3};
    float a2[ARRAY_SIZE] = {-12, 20.3, 26, 10, -7.36};

    // Concatenates array values in a new array.
    float array[ARRAY_SIZE * 2];
    for (int i = 0, j = 0; i < ARRAY_SIZE * 2; i++, j = i % ARRAY_SIZE)
    {
        array[i] = (i < 5) ? a1[j] : a2[j];
    }

    // Prints new array.
    for (int i = 0; i < ARRAY_SIZE * 2; i++)
    {
        printf(" %.2f", array[i]);
    }
    printf("\n");
}