/**
* 26-characters_counter.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program counts the number characters in a string without using strlen.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 128
#define NSHORT unsigned short

int main(void)
{
    // Prompts for a string.
    char* sentence = (char*)calloc(MAX_STRING_LENGTH, sizeof(char));
    printf("Enter a sentence (< 127 characters): ");
    fgets(sentence, MAX_STRING_LENGTH, stdin);

    // Counts the number characters in the string.
    NSHORT number_of_characters = 0;
    for (NSHORT i = 0; *(sentence + i) != '\0'; i++)
    {
        if (isalpha(*(sentence + i)))
            number_of_characters++;
    }

    // Prints the number of characters.
    printf("There are %hu characters in the sentence.\n", number_of_characters);
}