/**
* 21-linear_search_number_array.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program searchs a number in an array using linear search.
*/
#include <stdio.h>

#define ARRAY_SIZE 5

int main(void)
{
    // Prompts user for array values.
    float array[ARRAY_SIZE] = {15.0, 58.3, -96.2, 45, -14.3};

    // Prompts user for the number to be searched.
    float number;
    printf("Enter the search number : ");
    scanf(" %f", &number);

    // Searches the array using linear search.
    unsigned short found = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (array[i] == number)
        {
            found = 1;
            break;
        }
    }

    // Prints search result.
    if (found)
        printf("Found !");
    else
        printf("Not found !");
    printf("\n");
}