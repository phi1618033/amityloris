/**
* 26a-chars_blanks_words_counter.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program counts the number of characters, blanks and words of a sentence.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 128
#define PSHORT unsigned short

int main(void)
{
    // Prompts for a sentence.
    char* sentence = (char*)calloc(MAX_STRING_LENGTH, sizeof(char));
    printf("Enter a sentence (< 127 characters): ");
    fgets(sentence, MAX_STRING_LENGTH, stdin);

    // Counts the number characters in the string.
    PSHORT number_of_characters = 0;
    PSHORT number_of_blanks = 0;
    PSHORT number_of_words = 0;
    for (PSHORT i = 0, j = 0; *(sentence + i) != '\0'; i++)
    {
        // Counts characters, alphabetic as well as numeric characters.
        if ((*(sentence + i) >= 33) && (*(sentence + i) <= 126))
        {
            number_of_characters++;
            j++;  
        }
        
        if (isblank(*(sentence + i)))
        {
            number_of_blanks++;
        }
        
        // Counts the number of words. 
        // We have a word after a character or a group of characters followed by a blank or an apostrophe. 
        if (((isblank(*(sentence + i)) 
            || *(sentence + i) == '\'') 
            && j) 
                // or at the end of the sentence.        
                || (*(sentence + i + 1) == '\0' && j))
        {
            number_of_words++;
            j = 0;
        }
    }

    // Prints the number of characters, blanks and words.
    printf("There are %hu characters, %hu blanks and %hu words in the sentence.\n", 
        number_of_characters, number_of_blanks, number_of_words);
}