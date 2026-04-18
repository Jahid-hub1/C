#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "loans.txt"

typedef struct {
    int id;
    char assetTag[50];
    char status[20];
} Item;

void createFileIfMissing() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file != NULL) {
        fclose(file);
    }
}

int itemExists(int id) {
    FILE *file = fopen(FILE_NAME, "r");
    Item item;

    if (file == NULL) {
        return 0;
    }

    while (fscanf(file, "%d %49s %19s", &item.id, item.assetTag, item.status) == 3) {
        if (item.id == id) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void addItem(int id, char assetTag[], char status[]) {
    FILE *file;

    if (itemExists(id)) {
        printf("Item with ID %d already exists. Item not added.\n", id);
        return;
    }

    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d %s %s\n", id, assetTag, status);
    fclose(file);
    printf("Item added successfully.\n");
}

void displayItems() {
    FILE *file = fopen(FILE_NAME, "r");
    Item item;

    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nEquipment List\n");
    printf("ID\tAsset Tag\tStatus\n");
    printf("--------------------------------\n");

    while (fscanf(file, "%d %49s %19s", &item.id, item.assetTag, item.status) == 3) {
        printf("%d\t%s\t\t%s\n", item.id, item.assetTag, item.status);
    }

    fclose(file);
}

void searchItemById(int id) {
    FILE *file = fopen(FILE_NAME, "r");
    Item item;
    int found = 0;

    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    while (fscanf(file, "%d %49s %19s", &item.id, item.assetTag, item.status) == 3) {
        if (item.id == id) {
            printf("\nRecord Found\n");
            printf("ID: %d\n", item.id);
            printf("Asset Tag: %s\n", item.assetTag);
            printf("Status: %s\n", item.status);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }

    fclose(file);
}

int main() {
    createFileIfMissing();

    printf("Media Lab Equipment Loan Manager\n");
    printf("--------------------------------\n");

    addItem(101, "CAM-104", "A");
    addItem(102, "MIC-205", "L");
    addItem(103, "TRI-301", "A");
    addItem(102, "DUP-999", "A");

    displayItems();
    searchItemById(102);
    searchItemById(999);

    return 0;
}
