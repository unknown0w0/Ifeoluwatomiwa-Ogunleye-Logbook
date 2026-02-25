#include <stdio.h>

int main() {
    double sum = 0;
    double mean, median;
    double numbers[] = {90.0, 85.0, 70.0, 65.0, 50.0, 40.0, 20.0};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    mean = sum / n;

    if (n % 2 != 0) {
        median = numbers[n / 2];
    } else {
        median = (numbers[(n / 2) - 1] + numbers[n / 2]) / 2.0;
    }

    printf("Dataset Size: %d\n", n);
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);

    return 0;
}