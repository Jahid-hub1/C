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

void addItem() {
    FILE *file = fopen(FILE_NAME, "a");
    Item item;

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter item ID: ");
    scanf("%d", &item.id);
    printf("Enter asset tag: ");
    scanf("%49s", item.assetTag);
    printf("Enter status (A or L): ");
    scanf("%19s", item.status);

    fprintf(file, "%d %s %s\n", item.id, item.assetTag, item.status);
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

int main() {
    createFileIfMissing();

    printf("Media Lab Equipment Loan Manager\n");
    printf("--------------------------------\n");

    addItem();
    addItem();
    addItem();

    displayItems();

    return 0;
}
