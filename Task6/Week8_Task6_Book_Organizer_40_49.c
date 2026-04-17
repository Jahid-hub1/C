#include <stdio.h>

int main() {
    char books[8][100] = {
        "North Passage",
        "Echoes of the Atrium",
        "Archive Key",
        "Lantern Works",
        "Midnight Signal",
        "Paper Cities",
        "Silent Harbor",
        "Velvet Horizon"
    };

    int i;

    printf("Book Organizer - Grade 40-49\n\n");

    for (i = 0; i < 8; i++) {
        printf("Current Title: \"%s\"\n", books[i]);
        printf("First Title: \"%s\"\n", books[0]);
    }

    return 0;
}
