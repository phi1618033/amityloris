/**
* 24-matrix_arithmetic.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The program computes the tranpose of a matrix.
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
matrix compute_transpose(matrix M);
void print_matrix(matrix mtrx);

int main(void)
{
    matrix M = get_matrix(void);
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

matrix compute_transpose(matrix M)
{
    matrix T;
    T.number_of_rows = M.number_of_columns;
    T.number_of_columns = M.number_of_rows;
    T.values = (int**)calloc(M.number_of_rows, sizeof(int));
    if (T.values == NULL)
    {
        printf("Memory exhausted!\n");
        exit(0);
    }
    for (int i = 0; i < M.number_of_rows; i++)
    {
        T.values[i] = (int*)calloc(C.number_of_rows, sizeof(int));
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
