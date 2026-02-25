#include <stdio.h>
#include <math.h>
int main() {
    int i;
    int n;
    int sum = 0;
    printf("Enter a positive integer number of elements: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        if(i % 2 == 0){
        sum = sum + i;
        }
    }
    printf("%d", sum);

    return 0;}