/**
* 8-quadroot.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program computes the roots of a quadratic equation.
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompts values of a, b and c.
    float a, b, c;
    printf("Enter successively the value of a, b and c as in (ax^2 + bx + c = 0): ");
    scanf("%f %f %f", &a, &b, &c);

    // Computes the determinant.
    float delta = (b * b) - (4 * (a * c));

    // Checks the determinant sign.
    if (delta < 0)
    {
        printf("There no solution !\n");
        return 0;
    }

    // Generates roots.
    float x, x1;
    if (delta > 0)
    {
        x = (-b - sqrt(delta)) / (2.0 * a);
        x1 = (-b + sqrt(delta)) / (2.0 * a);

        printf("There are two solutions x1 = %.2f and x2 = %.2f\n", x, x1);
    }
    else
    {
        x = -b / (2.0 * a);
        printf("There is only one root, x = %.2f\n", x);
    }
}