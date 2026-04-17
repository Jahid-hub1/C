#include <stdio.h>

int main() {
    int days, i, choice;
    float temperatures[50];
    float sum, average, highest, lowest;

    printf("Temperature Logger\n");
    printf("------------------\n");
    printf("How many days do you want to record (max 50)? ");
    scanf("%d", &days);

    if (days <= 0 || days > 50) {
        printf("Invalid number of days.\n");
        return 1;
    }

    for (i = 0; i < days; i++) {
        printf("Enter temperature for day %d: ", i + 1);
        scanf("%f", &temperatures[i]);
    }

    do {
        printf("\nMenu\n");
        printf("1. Display all temperature readings\n");
        printf("2. Calculate average temperature overall\n");
        printf("3. Find highest and lowest temperature\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nTemperature Readings:\n");
                for (i = 0; i < days; i++) {
                    printf("Day %d: %.2f C\n", i + 1, temperatures[i]);
                }
                break;

            case 2:
                sum = 0.0;
                for (i = 0; i < days; i++) {
                    sum += temperatures[i];
                }
                average = sum / days;
                printf("\nAverage temperature: %.2f C\n", average);
                break;

            case 3:
                highest = temperatures[0];
                lowest = temperatures[0];
                for (i = 1; i < days; i++) {
                    if (temperatures[i] > highest) {
                        highest = temperatures[i];
                    }
                    if (temperatures[i] < lowest) {
                        lowest = temperatures[i];
                    }
                }
                printf("\nHighest temperature: %.2f C\n", highest);
                printf("Lowest temperature: %.2f C\n", lowest);
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid menu choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
