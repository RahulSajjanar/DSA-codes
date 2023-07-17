#include <stdio.h>


int main() {
    float matrix[100][100];
    int rows, cols, i, j;
    printf("Enter number of rows and columns of matrix: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter elements of matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    transpose(matrix, rows, cols);

    if (rows == cols) {
        inverse(matrix, rows);
    } else {
        printf("Matrix is not square, so it does not have an inverse.\n");
    }

    return 0;
}

void t(float matrix[][100], int rows, int cols) {
    float t[cols][rows];
    int i, j;
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            t[i][j] = matrix[j][i];
        }
    }
    printf("Transpose of matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++)
            {
            printf("%.2f ",matrix[i][j]);
            }
        printf("\n");
    }
}

void inverse(float matrix[][100], int n)
 {
    float inverseMatrix[100][100], temp;
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            inverseMatrix[i][j] = 0;
            if (i == j) {
                inverseMatrix[i][j] = 1;
            }
        }
    }
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
    printf("Inverse of matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f ", inverseMatrix[i][j]);
        }
        printf("\n");
    }
}


