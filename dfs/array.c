/**
* array.c
*
* Cheick Ali M. DIALLO
* contact@cheickalimdiallo.com
*
* Operations on arrays. Indexing is from 0 to N, position starts from 1.
*/
#include <stdio.h>

#define TRUE 1
#define FALSE 0

void traverse(short arr[], short lower_bound, short upper_bound)
{
    // Starts by the first item, then prints one item after another to the last.
    for (unsigned short i = lower_bound; i <= upper_bound; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void search(short arr[], short lower_bound, short upper_bound, short item)
{
    // Starts by the first item.
    unsigned char found = FALSE;
    for (unsigned short i = lower_bound; i <= upper_bound; ++i)
    {
        // Compares THE item to the current item.
        if (arr[i] == item)
        {
            // We have a match.
            found = TRUE;
            break;
        }
    }
    
    if (found)
        printf("Found !\n");
    else
        printf("Not found !\n");
}

void sort(short arr[], short lower_bound, short upper_bound)
{
    short temp, swapped;
    temp = 0;
    do
    {
        swapped = FALSE;
        for (unsigned short i = lower_bound; i <= upper_bound - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = TRUE;
            }
        }
    }
    while (swapped);
}

void insert(short arr[], short lower_bound, short total_number, short item, short position)
{
    // Checks that the position is within the boundaries.
    if ((position < lower_bound + 1) || (position > total_number))
    {
        printf("Invalid position !\n");
        return;
    }

    // Shifts items to the right before inserting new item.
    for (unsigned short i = total_number - 1; i > position - 1; --i)
        arr[i] = arr[i - 1];
    arr[position - 1] = item;
}

void delete(short arr[], short lower_bound, short total_number, short position)
{
    // Checks that the position is within the boundaries.
    if ((position < lower_bound + 1) || (position > total_number))
    {
        printf("Invalid position !\n");
        return;
    }

    // Shifts all items after position to the left, overwritting the item at position.
    unsigned short i;
    for (i = position - 1; i < total_number - 2; ++i)
        arr[i] = arr[i + 1];
    arr[i + 1] = 0;
}

void reverse(short arr[], short total_number)
{
    // Divides the array in two and swap elements at same place from both sides.
    short temp = 0;
    for (unsigned short i = 0; i < (total_number / 2); ++i)
    {
        temp = arr[i];
        arr[i] = arr[total_number - 1 - i];
        arr[total_number - 1 - i] = temp;
    }
}

int main(void)
{
    short marks[] = {8, 5, 3, 9, 2, 7, 20, 15, 12, 3, 5, 6, 13, 8, 2, 9, 5, 0, 0, 0};

    // traverse(marks, 0, 16);
    // insert(marks, 0, 20, 358, 3);
    traverse(marks, 0, 17);
    delete(marks, 0, 20, 17);
    traverse(marks, 0, 17);
    // reverse(marks, 17);
    // traverse(marks, 0, 16);
    // sort(marks, 0, 16);
    // traverse(marks, 0, 16);
}