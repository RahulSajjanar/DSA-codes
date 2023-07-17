#include <stdio.h>

int main()
{
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int m1_rows, m1_cols, m2_rows, m2_cols, i, j, k;

    printf("Enter rows and columns for matrix 1: ");
    scanf("%d %d", &m1_rows, &m1_cols);

    printf("Enter rows and columns for matrix 2: ");
    scanf("%d %d", &m2_rows, &m2_cols);

    if(m1_cols != m2_rows)
    {
        printf("Matrices cannot be multiplied!\n");
        return 0;
    }

    printf("Enter elements for matrix 1:\n");

    for(i=0; i<m1_rows; i++)
    {
        for(j=0; j<m1_cols; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements for matrix 2:\n");

    for(i=0; i<m2_rows; i++)
    {
        for(j=0; j<m2_cols; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for(i=0; i<m1_rows; i++)
    {
        for(j=0; j<m2_cols; j++)
        {
            result[i][j] = 0;

            for(k=0; k<m1_cols; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Result:\n");

    for(i=0; i<m1_rows; i++)
    {
        for(j=0; j<m2_cols; j++)
        {
            printf("%d ", result[i][j]);
        }

        printf("\n");
    }

    return 0;
}
