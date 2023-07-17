#include <stdio.h>

int main() {
    int matrix[100][100];
    int rows, cols, i, j;
    printf("Enter number of rows and columns of matrix: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter elements of matrix:\n");
    for (i = 0; i < rows; i++)
        {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    transpose(matrix, rows, cols);

}

void transpose(int matrix[][100], int rows, int cols)
{
    int transposeMatrix[cols][rows];
    int i, j;
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
            {
            transposeMatrix[i][j] = matrix[j][i];
        }
    }
    printf("Transpose of matrix:\n");
    for (i = 0; i < cols; i++)
        {
         for (j = 0; j < rows; j++)
            {
            printf("%.2d ", transposeMatrix[i][j]);
        }
        printf("\n");
    }
}

