/**
* 28-palindrome_checker.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program determines whether the entered character string (a word) is palindrome or not.
* A palindrome is a word, phrase, number, or other sequence of characters which reads 
* the same backward as forward, such as madam.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 32

int main(void)
{
    // Prompts for word.
    char word[MAX_LENGTH];
    printf("Enter a word (< 32 characters): ");
    scanf("%s", word);

    /* Checks whether the word is a palindrome. */
    unsigned short palindrome = 1;
    // Checks for odd number of characters.
    unsigned short word_length = strlen(word);
    if (word_length % 2 != 0)
    {
        // Gets index of character in the middle.
        unsigned short middle_character_index = (word_length - 1) / 2;
        /* Checks for a palindrome by comparing characters starting from the left to characters starting from 
           the right. */
        for (unsigned short i = 0, j = word_length - 1; 
            i < middle_character_index && j > middle_character_index; i++, j--)
        {
            if (toupper(word[i]) != toupper(word[j]))
                palindrome = 0;
        }
    }
    else
        palindrome = 0;

    // Prints result.
    if (palindrome)
        printf("It is a palindrome!");
    else
        printf("It is not a palindrome!");
    printf("\n");
}