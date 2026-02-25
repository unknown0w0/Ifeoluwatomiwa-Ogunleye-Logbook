#include <stdio.h>

int main() {
    double pop = 2000.0;
    float growth_rate = 0.15;
    int periods = 0;

    
    while (pop < 2000000.0) {
        pop = pop + (pop * growth_rate);
        periods++;
    }

    float years = periods / 2.0;

    printf("Final Population: %.2f\n", pop);
    printf("Total Time: %.1f years\n", years);

    return 0;
}