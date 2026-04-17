#include <stdio.h>

int main() {
    int tiktok1, youtube1, games1;
    int tiktok2, youtube2, games2;
    int week1Total, week2Total;
    float week1Average, week2Average;
    int dailyLimit = 180; // 3 hours per day

    printf("Weekly Screen-Time Tracker\n");
    printf("--------------------------\n");

    // Week 1 input
    printf("Enter WEEK 1 minutes for TikTok: ");
    scanf("%d", &tiktok1);

    printf("Enter WEEK 1 minutes for YouTube: ");
    scanf("%d", &youtube1);

    printf("Enter WEEK 1 minutes for Games: ");
    scanf("%d", &games1);

    // Week 2 input
    printf("\nEnter WEEK 2 minutes for TikTok: ");
    scanf("%d", &tiktok2);

    printf("Enter WEEK 2 minutes for YouTube: ");
    scanf("%d", &youtube2);

    printf("Enter WEEK 2 minutes for Games: ");
    scanf("%d", &games2);

    // Validation
    if (tiktok1 < 0 || youtube1 < 0 || games1 < 0 ||
        tiktok2 < 0 || youtube2 < 0 || games2 < 0) {
        printf("Error: Screen time cannot be negative.\n");
        return 1;
    }

    week1Total = tiktok1 + youtube1 + games1;
    week2Total = tiktok2 + youtube2 + games2;

    week1Average = week1Total / 7.0;
    week2Average = week2Total / 7.0;

    printf("\nResults\n");
    printf("-------\n");

    printf("Week 1 total: %d minutes\n", week1Total);
    printf("Week 1 daily average: %.2f minutes\n", week1Average);
    if (week1Average > dailyLimit) {
        printf("Week 1: Above recommended limit.\n");
    } else {
        printf("Week 1: Within recommended limit.\n");
    }

    printf("\nWeek 2 total: %d minutes\n", week2Total);
    printf("Week 2 daily average: %.2f minutes\n", week2Average);
    if (week2Average > dailyLimit) {
        printf("Week 2: Above recommended limit.\n");
    } else {
        printf("Week 2: Within recommended limit.\n");
    }

    printf("\nComparison\n");
    printf("----------\n");
    if (week2Total > week1Total) {
        printf("Total screen time increased in Week 2.\n");
    } else if (week2Total < week1Total) {
        printf("Total screen time decreased in Week 2.\n");
    } else {
        printf("Total screen time stayed the same in both weeks.\n");
    }

    return 0;
}