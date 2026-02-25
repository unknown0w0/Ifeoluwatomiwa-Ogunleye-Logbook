#include <stdio.h>
#include <math.h>

int main() {
    int counter;
    int var = 100;
    int run;
    printf("Enter a facking number nigga: ");
    scanf("%d", &run);

    for(counter = 0; counter < run; counter++)
    {
        var = var / 2;
        printf("Loop: %d Variable: %d\n", counter, var);
    }
    
}