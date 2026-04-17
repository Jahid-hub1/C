#include <stdio.h>

int main() {
    int tiktok, youtube, games;
    int total;
    float dailyAverage;
    int dailyLimit = 180; // 3 hours per day

    printf("Weekly Screen-Time Tracker\n");
    printf("--------------------------\n");

    printf("Enter weekly minutes for TikTok: ");
    scanf("%d", &tiktok);

    printf("Enter weekly minutes for YouTube: ");
    scanf("%d", &youtube);

    printf("Enter weekly minutes for Games: ");
    scanf("%d", &games);

    // Validation for negative input
    if (tiktok < 0 || youtube < 0 || games < 0) {
        printf("Error: Screen time cannot be negative.\n");
        return 1;
    }

    total = tiktok + youtube + games;
    dailyAverage = total / 7.0;

    printf("\nResults\n");
    printf("-------\n");
    printf("TikTok : %d minutes\n", tiktok);
    printf("YouTube: %d minutes\n", youtube);
    printf("Games  : %d minutes\n", games);
    printf("Total  : %d minutes\n", total);
    printf("Daily average: %.2f minutes\n", dailyAverage);

    if (dailyAverage > dailyLimit) {
        printf("Above recommended limit.\n");
    } else {
        printf("Within recommended limit.\n");
    }

    return 0;
}