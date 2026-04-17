#include <stdio.h>

int main() {
    int social1, video1, games1;
    int social2, video2, games2;

    int week1Total, week2Total, overallTotal;
    float week1Average, week2Average;

    printf("Weekly Screen-Time Tracker\n");
    printf("--------------------------\n");

    // Week 1
    printf("Enter WEEK 1 minutes for Social: ");
    scanf("%d", &social1);

    printf("Enter WEEK 1 minutes for Video: ");
    scanf("%d", &video1);

    printf("Enter WEEK 1 minutes for Games: ");
    scanf("%d", &games1);

    // Week 2
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

    printf("\nResults\n");
    printf("-------\n");

    printf("Week 1\n");
    printf("Social: %d minutes\n", social1);
    printf("Video : %d minutes\n", video1);
    printf("Games : %d minutes\n", games1);
    printf("Total : %d minutes\n", week1Total);
    printf("Daily average: %.2f minutes\n\n", week1Average);

    printf("Week 2\n");
    printf("Social: %d minutes\n", social2);
    printf("Video : %d minutes\n", video2);
    printf("Games : %d minutes\n", games2);
    printf("Total : %d minutes\n", week2Total);
    printf("Daily average: %.2f minutes\n\n", week2Average);

    printf("Overall total for both weeks: %d minutes\n", overallTotal);

    if (week2Total > week1Total) {
        printf("Screen time increased in Week 2.\n");
    } else if (week2Total < week1Total) {
        printf("Screen time decreased in Week 2.\n");
    } else {
        printf("Screen time stayed the same in both weeks.\n");
    }

    return 0;
}
