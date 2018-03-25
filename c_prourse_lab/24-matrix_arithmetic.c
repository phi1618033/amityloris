/**
* 24-matrix_arithmetic.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program adds, subtracts and multiplies two m by n matrices.
* For addition and subtraction, matrices must have the same number of rows and columns.
* For multiplication, the number of columns of the 1st matrix must be equal to the number of rows of the 2nd matrix.
* The resulting matrix has the number of rows of the 1st matrix and the number of columns of the second matrix.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned short number_of_rows;
    unsigned short number_of_columns;
    int** values;
}
matrix;

matrix get_matrix(void);
void adding(void);
void subtraction(void);
void multiplication(void);
void print_matrix(matrix mtrx);

int main(void)
{
    // Prompts for arithmetic operation.
    unsigned short operation;
    printf("Select operation:\n1.Addition\n2.Subtraction\n3.Multiplication\n: ");
    scanf("%hu", &operation);

    // Selects arithmetic operation.
    switch (operation)
    {
        case 1:
            adding();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiplication();
            break;
        default:
            printf("Invalid operation, restart !\n");
            break;
    }
}

/* Prompts user for matrix values */
matrix get_matrix(void)
{
    matrix mtrx;
    printf("Enter number of rows: ");
    scanf("%hu", &mtrx.number_of_rows);
    printf("Enter number of columns: ");
    scanf("%hu", &mtrx.number_of_columns);

    // Allocates memory for rows.
    mtrx.values = (int**)calloc(mtrx.number_of_rows, sizeof(int));
    if (mtrx.values == NULL)
    {
        printf("Memory exhausted!\n");
        exit(0);
    }

    for (int i = 0; i < mtrx.number_of_rows; i++)
    {
        // Allocates memory for columns of each row.
        mtrx.values[i] = (int*)calloc(mtrx.number_of_columns, sizeof(int));
        if (mtrx.values[i] == NULL)
        {
            printf("Memory exhausted!\n");
            exit(0);
        }

        for (int j = 0; j < mtrx.number_of_columns; j++)
        {
            printf("Enter value at (%i,%i): ", i, j);
            scanf(" %i", &mtrx.values[i][j]);
        }
    }

    return mtrx;
}

/* Adds two matrices. */
void adding(void)
{
    // Prompts for values.
    matrix A = get_matrix();
    matrix B = get_matrix();

    // Checks for addition possibility.
    if ((A.number_of_rows != B.number_of_rows) || (A.number_of_columns != B.number_of_columns))
    {
        printf("Matrices are from different orders, addition not possible !\n");
        exit(0);
    }

    // Declares and initializes new resulting matrix.
    matrix C;
    C.number_of_rows = A.number_of_rows;
    C.number_of_columns = B.number_of_columns;
    C.values = (int**)calloc(C.number_of_rows, sizeof(int));
    if (C.values == NULL)
    {
        printf("Memory exhausted!\n");
        exit(0);
    }
    for (int i = 0; i < A.number_of_rows; i++)
    {
        C.values[i] = (int*)calloc(C.number_of_rows, sizeof(int));
        if (C.values[i] == NULL)
        {
            printf("Memory exhausted!\n");
            exit(0);
        }
        for (int j = 0; j < B.number_of_columns; j++)
        {
            // Performs addition according to indices of value in matrices.
            *(*(C.values + i) + j) = *(*(A.values + i) + j) + *(*(B.values + i) + j);
        }
    }

    print_matrix(C);
}

/* Subtracts two matrices. */
void subtraction(void)
{
    // Prompts for values.
    matrix A = get_matrix();
    matrix B = get_matrix();

    // Checks for addition possibility.
    if ((A.number_of_rows != B.number_of_rows) || (A.number_of_columns != B.number_of_columns))
    {
        printf("Matrices are from different orders, subtraction not possible !\n");
        exit(0);
    }

    // Declares and initializes new resulting matrix.
    matrix C;
    C.number_of_rows = A.number_of_rows;
    C.number_of_columns = B.number_of_columns;
    C.values = (int**)calloc(C.number_of_rows, sizeof(int));
    if (C.values == NULL)
    {
        printf("Memory exhausted!\n");
        exit(0);
    }
    for (int i = 0; i < A.number_of_rows; i++)
    {
        C.values[i] = (int*)calloc(C.number_of_rows, sizeof(int));
        if (C.values[i] == NULL)
        {
            printf("Memory exhausted!\n");
            exit(0);
        }
        for (int j = 0; j < B.number_of_columns; j++)
        {
            // Performs subtraction according to indices of value in matrices.
            *(*(C.values + i) + j) = *(*(A.values + i) + j) - *(*(B.values + i) + j);
        }
    }

    print_matrix(C);
}

/* Multiplies two matrices. */
void multiplication(void)
{
    // Prompts for values.
    matrix A = get_matrix();
    matrix B = get_matrix();

    // Checks for multiplication possibility.
    if (A.number_of_columns != B.number_of_rows)
    {
        printf("Multiplication not possible !\n");
        exit(0);
    }

    // Declares and initializes new resulting matrix.
    matrix C;
    C.number_of_rows = A.number_of_rows;
    C.number_of_columns = B.number_of_columns;
    C.values = (int**)calloc(C.number_of_rows, sizeof(int));
    if (C.values == NULL)
    {
        printf("Memory exhausted!\n");
        exit(0);
    }
    // Performs multiplication with dot product.
    /* i and j identify values in C. i identifies rows in A and j identifies columns in B. k identifies columns in A
       and rows in B. */
    for (int i = 0; i < C.number_of_rows; i++)
    {
        C.values[i] = (int*)calloc(C.number_of_columns, sizeof(int));
        if (C.values[i] == NULL)
        {
            printf("Memory exhausted!\n");
            exit(0);
        }
        for (int j = 0, sum = 0; j < C.number_of_columns; j++, sum = 0)
        {
            for (int k = 0; k < A.number_of_columns; k++)
            {
                sum += *(*(A.values + i) + k) * *(*(B.values + k) + j);
            }
            *(*(C.values + i) + j) = sum;
        }
    }
    print_matrix(C);
}

/* Prints all matrix values. */
void print_matrix(matrix mtrx)
{
    printf("Resulting matrix is:\n");
    for (int i = 0; i < mtrx.number_of_rows; i++)
    {
        for (int j = 0; j < mtrx.number_of_columns; j++)
        {
            printf(" %i", *(*(mtrx.values + i) + j));
        }
        printf("\n");
    }
}
