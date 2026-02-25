#include <stdio.h>          // Allows use of printf

// Function to convert Fahrenheit to Celsius
float celsius(int F)        // Takes Fahrenheit value as input
{
    float fahr = (5.0 / 9.0) * (F - 32); // Conversion formula
    return fahr;   // Returns Fahrenheit value 
}

int main()
{
    int F;                  // Variable to hold Fahrenheit values

    printf("Fahrenheit\tCelsius\n"); // Prints table header
    printf("-------------------------\n"); // Prints a separator line

    for (F = 0; F <= 20; F++)        // Loop from 0 to 20 Fahrenheit
    {
        printf("%d\t\t%.2f\n", F, celsius(F)); // Print F and the converted Celsius value
    }

    return 0;              
}