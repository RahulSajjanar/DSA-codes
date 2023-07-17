#include <stdio.h>

void transpose(float matrix[][100], int rows, int cols)
 {
    float transposeMatrix[cols][rows];
    int i, j;

    // Transpose the matrix
    for (i = 0; i < cols; i++)
        {
        for (j = 0; j < rows; j++)
         {
            transposeMatrix[i][j] = matrix[j][i];
        }
    }

    // Print the transposed matrix
    printf("Transpose of matrix:\n");
    for (i = 0; i < cols; i++)
        {
          for (j = 0; j < rows; j++)
           {
            printf("%.2f ", transposeMatrix[i][j]);
        }
        printf("\n");
    }
}

void inverse(float matrix[][100], int n) {
    float inverseMatrix[100][100], temp;
    int i, j, k;

    // Initialize the inverse matrix as an identity matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            inverseMatrix[i][j] = 0;
            if (i == j) {
                inverseMatrix[i][j] = 1;
            }
        }
    }

    // Perform Gaussian elimination to find the inverse matrix
    for (k = 0; k < n; k++) {
        temp = matrix[k][k];
        for (j = 0; j < n; j++) {
            matrix[k][j] /= temp;
            inverseMatrix[k][j] /= temp;
        }
        for (i = 0; i < n; i++) {
            if (i != k) {
                temp = matrix[i][k];
                for (j = 0; j < n; j++) {
                    matrix[i][j] -= matrix[k][j] * temp;
                    inverseMatrix[i][j] -= inverseMatrix[k][j] * temp;
                }
            }
        }
    }

    // Print the inverse matrix
    printf("Inverse of matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f ", inverseMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float matrix[100][100];
    int rows, cols, i, j;

    // Read in the matrix from user input
    printf("Enter number of rows and columns of matrix: ");
    scanf("%d %d", &r, &c);
    printf("Enter elements of matrix:\n");
    for (i = 0; i < rows; i++)
        {
        for (j = 0; j < cols; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }
    transpose(matrix, rows, cols);

    if (rows == cols)
        {
        inverse(matrix, rows);
    } else {
        printf("Matrix is not square, so it does not have an inverse.\n");
    }

    return 0;
}
