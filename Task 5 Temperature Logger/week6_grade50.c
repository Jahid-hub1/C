#include <stdio.h>

int main() {
    int month, startWeekday;
    int day, daysInMonth;
    int saturdayCount = 0, sundayCount = 0;

    const char *monthNames[] = {
        "",
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Enter month number (1-12): ");
    scanf("%d", &month);

    printf("Enter starting weekday (1 = Monday, 7 = Sunday): ");
    scanf("%d", &startWeekday);

    if (month < 1 || month > 12) {
        printf("Invalid month. Please enter a value between 1 and 12.\n");
        return 1;
    }

    if (startWeekday < 1 || startWeekday > 7) {
        printf("Invalid weekday. Please enter a value between 1 and 7.\n");
        return 1;
    }

    if (month == 2) {
        daysInMonth = 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    printf("\n%s 2025\n", monthNames[month]);
    printf("Mon Tue Wed Thu Fri Sat Sun\n");

    for (day = 1; day < startWeekday; day++) {
        printf("    ");
    }

    for (day = 1; day <= daysInMonth; day++) {
        int currentWeekday = ((startWeekday + day - 2) % 7) + 1;

        printf("%3d ", day);

        if (currentWeekday == 6) {
            saturdayCount++;
        } else if (currentWeekday == 7) {
            sundayCount++;
        }

        if ((day + startWeekday - 1) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n\nNumber of Saturdays: %d\n", saturdayCount);
    printf("Number of Sundays: %d\n", sundayCount);

    return 0;
}
