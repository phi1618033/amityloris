/**
* string_concatenation.c
*
* DIALLO CHEICK ALI MOUSSA
* Bachelor of Computer Applications
* A1922517022(el)
* diallo.c@valorisuniversity.com
*
* 
* The program concatenate two strings.
*/
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

int main(void)
{
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];

    printf("Enter first string (less than 1024 characters): ");
    fgets(str1, MAX_STRING_LENGTH, stdin);
    printf("Enter second string (less than 1024 characters): ");
    fgets(str2, MAX_STRING_LENGTH, stdin);

    unsigned short str1_size = strlen(str1) - 1;
    unsigned short str2_size = strlen(str2) - 1;
    unsigned short cstr_size = str1_size + str2_size + 1;
    char cstr[cstr_size];

    short i = 0;
    for (int j = 0; j < str1_size; ++i, ++j)
        cstr[i] = str1[j];
    for (int k = 0; k < str2_size; ++i, ++k)
        cstr[i] = str2[k];
    
    cstr[i] = '\0';

    printf("Concatenated string is : %s\n", cstr);
}