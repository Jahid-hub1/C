#include <stdio.h>

int main() {
    int millilitres;
    float litres, cups;

    printf("Hydration Tracker - Basic Conversion\n");
    printf("-----------------------------------\n");
    printf("Enter the amount of water consumed in one day (ml): ");
    scanf("%d", &millilitres);

    litres = millilitres / 1000.0;
    cups = millilitres / 240.0;

    printf("\nWater Intake Summary\n");
    printf("--------------------\n");
    printf("Millilitres: %d ml\n", millilitres);
    printf("Litres: %.2f L\n", litres);
    printf("Cups: %.2f\n", cups);

    return 0;
}
