/**
* 27-string_to_string_copy.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program copies the contents of one string to another without using strcpy ()
* function.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 128

void copy_with_arrays(void)
{
    // Initialization.
    char str_a[] = "I am Cheick Ali M. DIALLO.";
    
    // Copies content of the 1st string into the 2nd.
    unsigned short str_a_length = strlen(str_a);
    // strlen does not count the terminating NUL(\0).
    char str_b[str_a_length + 1];
    unsigned short i = 0;
    for (; i < str_a_length; i++)
        str_b[i] = str_a[i];
    str_b[i] = '\0';

    // Prints content of the 2nd string.
    printf("%s\n", str_b);
}

void copy_with_pointers(void)
{
    // Initialization.
    char* str_a = (char*)calloc(MAX_STRING_LENGTH, sizeof(char));
    sprintf(str_a, "I am Cheick Ali M. DIALLO.");
    
    // Copies content of the 1st string into the 2nd.
    // strlen does not count the terminating NUL(\0).
    char* str_b = (char*)calloc(strlen(str_a) + 1, sizeof(char));
    char* str_b_ = str_b;
    // unsigned short i = 0;
    while (*str_a != '\0')
        *str_b_++ = *str_a++;
    *str_b_ = '\0';

    // Prints content of the 2nd string.
    printf("%s\n", str_b);
}

int main(void)
{
    copy_with_pointers();
}