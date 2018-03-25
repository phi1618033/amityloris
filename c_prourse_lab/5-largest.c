/**
* 5-largest.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program finds the largest of three numbers.
*/
#include <stdio.h>

int main(void)
{
    // Prompts for three numbers.
    int a, b, c, largest;
    printf("Enter three integers: ");
    scanf("%i %i %i", &a, &b, &c);

    // Compare the three to find the largest.
    largest = (a > b || a == b) ? a : b;
    largest = (largest > c || largest == c) ? largest : c;

    // Prints the largest number.
    printf("The largest is %i\n", largest);
}