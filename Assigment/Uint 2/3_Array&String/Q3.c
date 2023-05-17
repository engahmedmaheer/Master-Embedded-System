#include <stdio.h>

int main() {
    int matrix[10][10];
    int transpose[10][10];
    int rows, columns;
    int i, j;
    
    // Input matrix size from user
    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d %d", &rows, &columns);
    
    // Input matrix elements from user
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Transpose the matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    // Display the transpose of the matrix
    printf("The transpose of the matrix is:\n");
    for (i = 0; i < columns; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
