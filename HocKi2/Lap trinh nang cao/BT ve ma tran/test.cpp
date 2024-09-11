#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix and input its values
int** inputMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));

    // Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Input values for each element
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    return matrix;
}

// Function to display a matrix
void displayMatrix(int** matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free memory allocated for a matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows, cols;

    // Input the dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Input and display the matrix
    int** matrix = inputMatrix(rows, cols);
    displayMatrix(matrix, rows, cols);

    // Free the allocated memory
    freeMatrix(matrix, rows);

    return 0;
}