/**
* 16-input_type.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program prints 1 if input character is capital, 2 if input character is a lowercase alphabet, 3 if
* input character is a digit and 4 if some other special character.
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // Prompts for a single character.
    printf("Enter a single character: ");
    char c;
    scanf("%c", &c);

    // Checks character type.
    if (isalnum(c))
    {
        if (isalpha(c))
        {
            if(isupper(c))
                printf("1");
            else
                printf("2");
        }
        else
            printf("3");
    }
    else
        printf("4");
    printf("\n");
}