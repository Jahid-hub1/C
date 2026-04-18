#include <stdio.h>

int main() {
    int month, startWeekday;
    int day;
    int totalDays = 30;   // Fixed number of days for the basic version

    const char *monthNames[] = {
        "",
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Enter month number (1-12): ");
    scanf("%d", &month);

    printf("Enter starting weekday (1 = Monday, 7 = Sunday): ");
    scanf("%d", &startWeekday);

    printf("\n%s 2025\n", monthNames[month]);
    printf("Mon Tue Wed Thu Fri Sat Sun\n");

    for (day = 1; day < startWeekday; day++) {
        printf("    ");
    }

    for (day = 1; day <= totalDays; day++) {
        printf("%3d ", day);
        if ((day + startWeekday - 1) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}
