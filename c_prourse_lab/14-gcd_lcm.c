/**
* 14-gcd_lcm.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program finds the GCD and LCM of two integers.
*/
#include <stdio.h>
#include <stdlib.h>

/* Computes the GCD of two integers following Euclid's algorithm. */
int gcd(int x, int y)
{
    // If x = 0, then GCD(x, y) = |y|. The converse is true.
    if (x == 0)
        return abs(y);

    if (y == 0)
        return abs(x);
    
    // GCD(x,y) = GCD(y, x modulo y).
    int r = x % y;
    return gcd(y, r);
}

/* Computes the LCM by reduction of the GCD; LCM(x, y) = |x.y|/GCD(x,y). */
int lcm(int x, int y, int gcd)
{
    int result = (int)(abs(x * y) / gcd);
    return result;
}

int main(void)
{
    // Prompts for two integers and operation to be performed.
    int a, b;
    do
    {
        printf("Enter two integers : ");
        scanf("%i %i", &a, &b);
    }
    while (a == 0 && b == 0);

    // Call operation function.
    int gcd_result = gcd(a, b);
    int lcm_result = lcm(a, b, gcd_result);

    // Prints result.
    printf("The GCD is %i and the LCM is %i\n", gcd_result, lcm_result);
}