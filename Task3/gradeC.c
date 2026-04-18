#include <stdio.h>

int main() {
    int millilitres;
    int dayCount = 0;
    int totalMl = 0;
    char choice;
    float litres, cups, totalLitres;

    printf("Hydration Tracker - Multi-Day Conversion\n");
    printf("----------------------------------------\n");

    do {
        printf("Enter the amount of water consumed for day %d (ml): ", dayCount + 1);
        scanf("%d", &millilitres);

        if (millilitres < 0) {
            printf("Invalid input. Please enter 0 or a positive value.\n");
        } else {
            litres = millilitres / 1000.0;
            cups = millilitres / 240.0;

            printf("Litres: %.2f L | Cups: %.2f\n", litres, cups);

            totalMl += millilitres;
            dayCount++;
        }

        printf("Add another day? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    totalLitres = totalMl / 1000.0;

    printf("\nSummary\n");
    printf("-------\n");
    printf("You tracked %d day(s). Total: %.2f L\n", dayCount, totalLitres);

    return 0;
}
