#include <stdio.h>

int main() {
    // Weekly screen time in minutes
    int social = 300;
    int video = 420;
    int games = 250;

    int total = social + video + games;

    printf("Weekly Screen-Time Tracker\n");
    printf("--------------------------\n");
    printf("Social: %d minutes\n", social);
    printf("Video : %d minutes\n", video);
    printf("Games : %d minutes\n", games);
    printf("Total : %d minutes\n", total);

    return 0;
}
