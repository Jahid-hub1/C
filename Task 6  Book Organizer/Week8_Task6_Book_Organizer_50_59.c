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
    char book0Lower[100];
    char currentLower[100];
    int i;

    printf("Book Organizer - Grade 50-59\n\n");

    printf("Before: ");
    printBooks(books);

    for (i = 1; i < 8; i++) {
        toLowerCase(books[0], book0Lower);
        toLowerCase(books[i], currentLower);

        if (strcmp(currentLower, book0Lower) < 0) {
            strcpy(temp, books[0]);
            strcpy(books[0], books[i]);
            strcpy(books[i], temp);
        }
    }

    printf("After : ");
    printBooks(books);

    return 0;
}
