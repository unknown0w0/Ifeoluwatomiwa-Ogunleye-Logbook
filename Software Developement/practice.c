#include <stdio.h>

int main() {
    int n;
    printf("Enter a five-digit number: ");
    scanf("%d", &n);

    int d1 = n / 10000;
    int d2 = (n % 10000) / 1000;
    int d3 = (n % 1000) / 100;
    int d4 = (n % 100) / 10;
    int d5 = n % 10;

    printf("%d   %d   %d   %d   %d\n", d1, d2, d3, d4, d5);

    return 0;
}