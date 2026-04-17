#include <stdio.h>

int main() {
    // Weekly screen time in minutes
    int tiktok = 300;
    int youtube = 420;
    int games = 250;

    int total = tiktok + youtube + games;

    printf("Weekly Screen-Time Tracker\n");
    printf("--------------------------\n");
    printf("TikTok : %d minutes\n", tiktok);
    printf("YouTube: %d minutes\n", youtube);
    printf("Games  : %d minutes\n", games);
    printf("Total  : %d minutes\n", total);

    return 0;
}