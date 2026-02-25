/* This program adds two integer numbers */
#include <stdio.h>
int main()
{
    int a, b, c, sum; /* variable declarations */
    printf("Enter first integer\n"); /* prompt the user */
    scanf( "%d", &a); /* read first integer */
    printf("Enter second integer\n"); /* prompt the user */
    scanf( "%d", &b); /* read second integer */
    printf("Enter third integer\n"); /* prompt the user */
    scanf( "%d", &c); /* read third integer */
    sum = a + b + c; /* calculate the sum */
    printf( "Sum = %d\n", sum ); /* print the calculated sum*/
    return 0; /* indicate that program ended successfully */
}