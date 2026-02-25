#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;

    for(i =1; i <= 6; i++) {
        
        printf("%10d", 1 + (rand(time()) % 6));

        if(i % 5 == 0) {
            printf("\n");
        }
    
    }

    return 0;

}