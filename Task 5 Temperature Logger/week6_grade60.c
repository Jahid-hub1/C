#include <stdio.h>

int main() {
    int month;
    int day, daysInMonth;
    int saturdayCount = 0, sundayCount = 0;
    int startWeekday;
    int totalDaysBeforeMonth = 0;
    int monthIndex;

    const char *monthNames[] = {
        "",
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int monthLengths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter month number (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Invalid month. Please enter a value between 1 and 12.\n");
        return 1;
    }

    daysInMonth = monthLengths[month];

    for (monthIndex = 1; monthIndex < month; monthIndex++) {
        totalDaysBeforeMonth += monthLengths[monthIndex];
    }

    /*
       1 January 2025 is a Wednesday.
       Using Monday = 1, Tuesday = 2, Wednesday = 3, ..., Sunday = 7.
       We add the number of days before the selected month and use modulo 7
       to find the weekday of the 1st day of that month.
    */
    startWeekday = ((3 - 1 + totalDaysBeforeMonth) % 7) + 1;

    printf("\n%s 2025\n", monthNames[month]);
    printf("The 1st day of this month is weekday number: %d\n", startWeekday);
    printf("(1 = Monday, 7 = Sunday)\n\n");
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
