#include <stdio.h>

void transpose(float matrix[][100], int rows, int cols) {
    float transposeMatrix[cols][rows];
    int i, j;

    // Transpose the matrix
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            transposeMatrix[i][j] = matrix[j][i];
        }
    }

    // Print the transposed matrix
    printf("Transpose of matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%.2f ", transposeMatrix[i][j]);
        }
        printf("\n");
    }
}



int main() {
    float matrix[100][100];
    int rows, cols, i, j;

    // Read in the matrix from user input
    printf("Enter number of rows and columns of matrix: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter elements of matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }
    for (i = 0; i < rows; i++)
        {
        for (j = 0; j < cols; j++)
        {
            printf("%f", matrix[i][j]);

            printf("\n");
        }
    }


    // Transpose the matrix and print it
    transpose(matrix, rows, cols);


}
