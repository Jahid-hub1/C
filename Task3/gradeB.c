#include <stdio.h>

int main() {
    int choice, amount;
    int totalMl = 0;
    int mlEntries = 0, bottleEntries = 0, cupEntries = 0;
    char again;
    float totalLitres;

    printf("Hydration Tracker - Multi-Type Tracking\n");
    printf("---------------------------------------\n");

    do {
        printf("\nWhat would you like to add?\n");
        printf("1: Millilitres\n");
        printf("2: Bottles (500 ml each)\n");
        printf("3: Cups (240 ml each)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("How many millilitres? ");
            scanf("%d", &amount);

            if (amount < 0) {
                printf("Invalid input. Amount must be 0 or more.\n");
            } else {
                totalMl += amount;
                mlEntries++;
                printf("Added %d ml.\n", amount);
            }
        } else if (choice == 2) {
            printf("How many bottles? ");
            scanf("%d", &amount);

            if (amount < 0) {
                printf("Invalid input. Amount must be 0 or more.\n");
            } else {
                totalMl += amount * 500;
                bottleEntries++;
                printf("Added %d ml.\n", amount * 500);
            }
        } else if (choice == 3) {
            printf("How many cups? ");
            scanf("%d", &amount);

            if (amount < 0) {
                printf("Invalid input. Amount must be 0 or more.\n");
            } else {
                totalMl += amount * 240;
                cupEntries++;
                printf("Added %d ml.\n", amount * 240);
            }
        } else {
            printf("Invalid menu choice. Please select 1, 2, or 3.\n");
        }

        printf("Add another entry? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    totalLitres = totalMl / 1000.0;

    printf("\nSummary:\n");
    printf("--------\n");
    printf("Total: %d ml (%.2f L)\n", totalMl, totalLitres);
    printf("Entries - Bottles: %d, Cups: %d, Millilitres: %d\n",
           bottleEntries, cupEntries, mlEntries);

    return 0;
}
