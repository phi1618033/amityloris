/**
* 1-perarea.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* A program to find the area and perimeter of a square or a rectangle.
*/
#include <stdio.h>

#define SIDE "side"
#define LENGTH "length"
#define WIDTH "width"

float prompt_for_value(char* value_name)
{
    float value;
    printf("Enter value of %s: ", value_name);
    scanf("%f", &value);
    return value;
}

void compute_square_perimeter(void)
{
    float side = prompt_for_value("side");
    float perimeter = side * 4.0;
    printf("The perimeter is %.2f\n", perimeter);
}

void compute_square_area(void)
{
    float side = prompt_for_value("side");
    float area = side * side;
    printf("The area is %.2f\n", area);
}

void compute_rectangle_perimeter(void)
{
    float length = prompt_for_value("length");
    float width = prompt_for_value("width");
    float perimeter = (length + width) * 2.0;
    printf("The perimeter is %.2f\n", perimeter);
}

void compute_rectangle_area(void)
{
    float length = prompt_for_value("length");
    float width = prompt_for_value("width");
    float area = length * width;
    printf("The area is %.2f\n", area);
}

int main(void)
{
    short option;
    printf("------------Welcome to Perarea-------------\n");
    printf("1.Perimeter of a square\n2.Perimeter of a rectangle\n3.Area of a square\n4.Area of a rectangle\nPress: ");
    scanf("%i", &option);

    switch(option)
    {
        case 1:
            compute_square_perimeter();
            break;
        case 2:
            compute_rectangle_perimeter();
            break;
        case 3:
            compute_square_area();
            break;
        case 4:
            compute_rectangle_area();
            break;
        default:
            printf("You press an invalid option, exiting...\n");
            break;
    }
}