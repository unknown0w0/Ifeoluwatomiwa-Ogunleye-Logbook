#include <stdio.h>
#include <stdlib.h> 

int main() {
    int num, temp;
    int sum = 0;
    int count = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);


    if (temp == 0) {
        count = 1;
        sum = 0;
    } else {
        while (temp > 0) {
            sum += temp % 10;   
            count++;            
            temp /= 10;         
        }
    }

    printf("\n Results for: %d \n", num);
    printf("Number of digits: %d\n", count);
    printf("Sum of digits:    %d\n", sum);

    return 0;
}