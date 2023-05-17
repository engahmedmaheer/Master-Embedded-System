#include <stdio.h>

int main() {
    int n, i;
    float num, max, sum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter a positive number: ");
        scanf("%f", &num);
        if(num <= 0) {
            printf("Invalid Input. Enter a positive number\n");
            i--;
            continue;
        }
        if(i == 0 || num > max) {
            max = num;
        }
        sum += num;
    }
    printf("The average of the maximum of %d numbers is %.2f\n", n, (sum - max) / (n - 1));
    return 0;
}
