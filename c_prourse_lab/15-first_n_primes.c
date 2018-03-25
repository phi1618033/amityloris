/**
* 15-first_n_primes.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program generates the first n prime numbers.
* A prime number (or a prime) is a natural number greater than 1 that has no positive divisors other than 1 and itself.
* A natural number greater than 1 that is not a prime number is called a composite number.
*/
#include <stdio.h>

int main(void)
{
    // Prompts for n.
    int n = 0;
    do
    {
        printf("Enter a positive integer: ");
        scanf("%i", &n);
    }
    while (n < 1);

    // Generates the first n prime numbers.
    // Prints the first number in the sequence.
    printf("2");
    short prime = 0;
    // Iterates from the number following the first prime to n.
    for (int i = 3, j = 1; j < n; i++)
    {
        // Checks for an odd number.
        if (i % 2 != 0)
        {
            prime = 1;
            // Checks that all previous odd numbers are not factors of the current number.
            for (int k = 2; k < i; k++)
            {
                if (k % 2 != 0)
                {
                    if (i % k == 0)
                    {
                        prime = 0;
                        break;
                    }
                }
            }

            if (prime)
            {
                printf(" %i", i);
                j++;
            }
        }
    }
    printf("\n");
}