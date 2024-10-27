#include <stdio.h>

int main() {
    int numbers[5];
    int max, min;

    // Prompt user for input
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Initialize max and min with the first number
    max = min = numbers[0];

    // Find maximum and minimum values
    for (int i = 1; i < 5; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    // Output the results
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}
