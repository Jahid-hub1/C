#include <stdio.h>

int main() {
    int social1, video1, games1;
    int social2, video2, games2;

    int week1Total, week2Total, overallTotal;
    float week1Average, week2Average, overallDailyAverage;

    printf("Weekly Screen-Time Tracker\n");
    printf("--------------------------\n");

    // Week 1 input
    printf("Enter WEEK 1 minutes for Social: ");
    scanf("%d", &social1);

    printf("Enter WEEK 1 minutes for Video: ");
    scanf("%d", &video1);

    printf("Enter WEEK 1 minutes for Games: ");
    scanf("%d", &games1);

    // Week 2 input
    printf("\nEnter WEEK 2 minutes for Social: ");
    scanf("%d", &social2);

    printf("Enter WEEK 2 minutes for Video: ");
    scanf("%d", &video2);

    printf("Enter WEEK 2 minutes for Games: ");
    scanf("%d", &games2);

    week1Total = social1 + video1 + games1;
    week2Total = social2 + video2 + games2;
    overallTotal = week1Total + week2Total;

    week1Average = week1Total / 7.0;
    week2Average = week2Total / 7.0;
    overallDailyAverage = overallTotal / 14.0;

    printf("\nResults\n");
    printf("-------\n");
    printf("Week 1 total: %d minutes\n", week1Total);
    printf("Week 1 daily average: %.2f minutes\n", week1Average);

    printf("Week 2 total: %d minutes\n", week2Total);
    printf("Week 2 daily average: %.2f minutes\n", week2Average);

    printf("Overall total for 2 weeks: %d minutes\n", overallTotal);
    printf("Overall daily average for 2 weeks: %.2f minutes\n", overallDailyAverage);

    return 0;
}
