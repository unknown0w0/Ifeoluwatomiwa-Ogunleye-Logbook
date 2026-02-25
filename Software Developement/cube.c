#include <stdio.h>

int main() {
    int number = 5;

    printf("The original value of number is %d", number);

    cubeByReference( &number );

    printf("The new value of number is %d\n", number);

    return 0;
}

void cubeByReference( int *nPtr )
{
    
}