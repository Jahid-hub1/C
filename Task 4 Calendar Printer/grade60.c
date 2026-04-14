#include <stdio.h>

#define SIZE 50
#define SENTINEL -999.0f

int countEntries(float temperatures[]) {
    int count = 0;
    while (count < SIZE && temperatures[count] != SENTINEL) {
        count++;
    }
    return count;
}

void displayReadings(float temperatures[]) {
    int i = 0;
    printf("\nTemperature Readings:\n");
    while (i < SIZE && temperatures[i] != SENTINEL) {
        printf("Day %d: %.2f C\n", i + 1, temperatures[i]);
        i++;
    }
}

float calculateAverage(float temperatures[]) {
    int i = 0, count = 0;
    float sum = 0.0f;

    while (i < SIZE && temperatures[i] != SENTINEL) {
        sum += temperatures[i];
        count++;
        i++;
    }

    if (count == 0) {
        return 0.0f;
    }

    return sum / count;
}

void findHighestLowest(float temperatures[], float *highest, float *lowest) {
    int i = 1;
    *highest = temperatures[0];
    *lowest = temperatures[0];

    while (i < SIZE && temperatures[i] != SENTINEL) {
        if (temperatures[i] > *highest) {
            *highest = temperatures[i];
        }
        if (temperatures[i] < *lowest) {
            *lowest = temperatures[i];
        }
        i++;
    }
}

void countAboveBelowThreshold(float temperatures[], float threshold) {
    int i = 0, above = 0, below = 0;

    while (i < SIZE && temperatures[i] != SENTINEL) {
        if (temperatures[i] > threshold) {
            above++;
        } else if (temperatures[i] < threshold) {
            below++;
        }
        i++;
    }

    printf("\nDays above %.2f C: %d\n", threshold, above);
    printf("Days below %.2f C: %d\n", threshold, below);
}

void weeklyAverages(float temperatures[]) {
    int i = 0, week = 1;

    while (i < SIZE && temperatures[i] != SENTINEL) {
        float sum = 0.0f;
        int count = 0;

        while (count < 7 && i < SIZE && temperatures[i] != SENTINEL) {
            sum += temperatures[i];
            count++;
            i++;
        }

        printf("Week %d average: %.2f C\n", week, sum / count);
        week++;
    }
}

int main() {
    int days, i, choice;
    float temperatures[SIZE];
    float highest, lowest, threshold;

    for (i = 0; i < SIZE; i++) {
        temperatures[i] = SENTINEL;
    }

    printf("Temperature Logger\n");
    printf("------------------\n");
    printf("How many days do you want to record (max 50)? ");
    scanf("%d", &days);

    if (days <= 0 || days > SIZE) {
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
        printf("4. Count days above and below a threshold\n");
        printf("5. Calculate weekly average temperature\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayReadings(temperatures);
                break;

            case 2:
                printf("\nAverage temperature: %.2f C\n", calculateAverage(temperatures));
                break;

            case 3:
                findHighestLowest(temperatures, &highest, &lowest);
                printf("\nHighest temperature: %.2f C\n", highest);
                printf("Lowest temperature: %.2f C\n", lowest);
                break;

            case 4:
                printf("Enter threshold temperature: ");
                scanf("%f", &threshold);
                countAboveBelowThreshold(temperatures, threshold);
                break;

            case 5:
                printf("\nWeekly Averages:\n");
                weeklyAverages(temperatures);
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
