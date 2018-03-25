/**
* 25-char_detector.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program detects the occurrence of a character in a given string.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 128

int main(void)
{
    // Prompts user for a sentence.
    char* sentence = (char*)calloc(MAX_STRING_LENGTH, sizeof(char));
    printf("Enter a sentence (< 128 characters):\n");
    fgets(sentence, MAX_STRING_LENGTH, stdin);
    
    // Prompts user for a character to search for.
    char c;
    printf("Enter character to search: ");
    scanf("%c", &c);

    // Searches for c in sentence.
    unsigned short found = 0;
    for (int i = 0, sentence_length = strlen(sentence); i < sentence_length; i++)
    {
        if (*(sentence + i) == c)
        {
            found = 1;
            break;
        }
    }

    // Prints search results.
    if (found)
        printf("Found !");
    else
        printf("Not found !");
    printf("\n");
}