#include <stdio.h>

int main() {
    int matrix1[2][2], matrix2[2][2], result[2][2];
    int i, j;
    
    // Input first matrix
    printf("Enter the elements of first matrix:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    // Input second matrix
    printf("Enter the elements of second matrix:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    // Add the two matrices
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    // Display the result
    printf("The sum of the two matrices is:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
