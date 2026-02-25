#include <stdio.h>
#include <math.h>
int main(){

        // COMPOUND INTEREST CALCULATOR
    double principal = 0.0;
    double rate = 0.0;
    int years = 0;
    int timesCompounded = 0;
    double total = 0.0;

    printf("COMPOUND INTEREST CALCULATOR\n");

    printf("Enter the principal : ");
    scanf("%lf", &principal);

    printf("Enter the interest rate : ");
    scanf("%lf", &rate);

    printf("Enter how many years : ");
    scanf("%d", &years);

    printf("Enter # of times compounded a year : ");
    scanf("%d", &timesCompounded);

    total = principal * pow(1 + (rate / timesCompounded), years);

    printf("Your total is %.2lf", total);

    return 0;
}