#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char source[], char dest[]) {
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        dest[i] = tolower((unsigned char)source[i]);
    }
    dest[i] = '\0';
}

void printBooks(char books[8][100]) {
    int i;
    for (i = 0; i < 8; i++) {
        printf("\"%s\"", books[i]);
        if (i < 7) {
            printf(", ");
        }
    }
    printf("\n");
}

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

    char temp[100];
    char firstLower[100];
    char currentLower[100];
    int i, j;

    printf("Book Organizer - Grade 60-69\n\n");

    printf("Before: ");
    printBooks(books);

    for (i = 0; i < 7; i++) {
        for (j = i + 1; j < 8; j++) {
            toLowerCase(books[i], firstLower);
            toLowerCase(books[j], currentLower);

            if (strcmp(currentLower, firstLower) < 0) {
                strcpy(temp, books[i]);
                strcpy(books[i], books[j]);
                strcpy(books[j], temp);
            }
        }
    }

    printf("After : ");
    printBooks(books);

    return 0;
}
