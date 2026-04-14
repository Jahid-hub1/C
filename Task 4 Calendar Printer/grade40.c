#include <stdio.h>

int main() {
    int days, i;
    float temperatures[50];
    float sum = 0.0, average;

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

    printf("\nMenu\n");
    printf("1. Display all temperature readings\n");
    printf("2. Calculate average temperature overall\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nTemperature Readings:\n");
        for (i = 0; i < days; i++) {
            printf("Day %d: %.2f C\n", i + 1, temperatures[i]);
        }
    } else if (choice == 2) {
        for (i = 0; i < days; i++) {
            sum += temperatures[i];
        }
        average = sum / days;
        printf("\nAverage temperature: %.2f C\n", average);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
