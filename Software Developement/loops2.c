#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int sum = 0;
    printf("Enter a positive number: ");
    scanf("%d", &n);
    while (n >= 0){
       sum += n; 
        printf("Enter another number: ");
            scanf("%d", &n);
        
    }
    if(n < 0){
        printf("The sum is: %d\n", sum);
    }
    
    return 0;
}