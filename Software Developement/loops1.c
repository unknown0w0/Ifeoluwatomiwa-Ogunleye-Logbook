#include <stdio.h>
#include <math.h>


float average (int x, int y){
    return x + y / 2.0;
}

int main() {
    
    int x = 23;
    int y = 5;

    int avg = average(x, y);

    printf("%f", avg);
    
    return 0;
}


