#include <stdio.h>

int main(){
    float celsius, fahr, celsius1, fahr1;
    int bottom, step, upper;
    // initalization
    fahr = 0.0;
    bottom = 0;
    step = 20;
    upper = 300;

    printf("Fahrenhei\tCelsiusCelsius\tFahrenheit\n\n");
    while(fahr <= upper) {
        celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%3.0f%16.1f\n", fahr, celsius);
        fahr += step;
    }

    celsius1 = 0.0;
    printf("\n");

    printf("Celsiu \t Fahrenheit\n\n");
    while(celsius1 <= upper) {
        fahr1 = 9.0 * (celsius1 + 32.0) / 5.0;
        printf("%3.0f%16.2f\n", celsius1, fahr1);
        celsius1 += step;
    }

    printf("Reecrsed table\nFahrenheit\tCelsius\n\n");
    for(fahr = 300; fahr >= 0; fahr -= 20) {
    celsius = (5.0/9.0) * (fahr - 32.0);
    printf("%3.0f%10.2f\n", fahr, celsius);
    }
}
