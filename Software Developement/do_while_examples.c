#include <stdio.h>

int main() {
    // Example 1: Basic do-while loop to print numbers from 1 to 5
    int i = 1;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 5);
    printf("\n");

    // Example 2: Do-while loop to sum numbers until a negative number is entered
    int sum = 0;
    int num;
    do {
        printf("Enter a number (negative to stop): ");
        scanf("%d", &num);
        if (num >= 0) {
            sum += num;
        }
    } while (num >= 0);
    printf("Sum of positive numbers: %d\n", sum);

    // Example 3: Do-while loop for input validation (ensure positive number)
    int value;
    do {
        printf("Enter a positive number: ");
        scanf("%d", &value);
    } while (value <= 0);
    printf("You entered: %d\n", value);

    // Example 4: Do-while loop simulating a simple menu
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Option 1\n");
        printf("2. Option 2\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("You chose Option 1\n");
                break;
            case 2:
                printf("You chose Option 2\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
