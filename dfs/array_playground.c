/**
* array_playground.c
*
* Cheick Ali M. DIALLO
* contact@cheickalimdiallo.com
*
* Some functions of operations on arrays.
*/
#include <stdio.h>

void insert(short arr[], short lower_bound, short total_number, short item, short position)
{
    if ((position < lower_bound + 1) || (position > total_number))
    {
        printf("Invalid position !");
        return;
    }

    for (unsigned short i = total_number - 1; i > position - 1; --i)
        arr[i] = arr[i - 1];
    arr[position - 1] = item;
}

void delete(short arr[], short lower_bound, short total_number, short position)
{
    if ((position < lower_bound + 1) || (position > total_number))
    {
        printf("Invalid position !");
        return;
    }

    unsigned short i = position - 1;
    for (; i < total_number - 2; ++i)
        arr[i] = arr[i + 1];
    arr[i + 1] = 0;
}

void reverse(short arr[], short lower_bound, short total_number)
{
    short temp = 0;

    for (unsigned short i = lower_bound; i < (total_number / 2); ++i)
    {
        temp = arr[i];
        arr[i] = arr[total_number - 1 - i];
        arr[total_number - 1 - i] = temp;
    }
}

int main(void)
{
}