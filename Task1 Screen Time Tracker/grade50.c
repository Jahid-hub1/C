#include <stdio.h>

int main() {
    int social, video, games;
    int total;
    float dailyAverage;
    int dailyLimit = 180; // 3 hours per day

    printf("Weekly Screen-Time Tracker\n");
    printf("--------------------------\n");

    printf("Enter weekly minutes for Social: ");
    scanf("%d", &social);

    printf("Enter weekly minutes for Video: ");
    scanf("%d", &video);

    printf("Enter weekly minutes for Games: ");
    scanf("%d", &games);

    total = social + video + games;
    dailyAverage = total / 7.0;

    printf("\nResults\n");
    printf("-------\n");
    printf("Social: %d minutes\n", social);
    printf("Video : %d minutes\n", video);
    printf("Games : %d minutes\n", games);
    printf("Total : %d minutes\n", total);
    printf("Daily average: %.2f minutes\n", dailyAverage);

    if (dailyAverage > dailyLimit) {
        printf("Daily average is above the limit of %d minutes.\n", dailyLimit);
    } else if (dailyAverage == dailyLimit) {
        printf("Daily average is exactly at the limit of %d minutes.\n", dailyLimit);
    } else {
        printf("Daily average is below the limit of %d minutes.\n", dailyLimit);
    }

    return 0;
}
