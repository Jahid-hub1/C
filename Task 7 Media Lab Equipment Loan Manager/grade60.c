#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "loans.txt"
#define MAX_ITEMS 100

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

int addItem(int id, char assetTag[], char status[]) {
    FILE *file = fopen(FILE_NAME, "r");
    Item item;

    if (file != NULL) {
        while (fscanf(file, "%d %49s %19s", &item.id, item.assetTag, item.status) == 3) {
            if (item.id == id) {
                fclose(file);
                return 0;
            }
        }
        fclose(file);
    }

    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        return 0;
    }

    fprintf(file, "%d %s %s\n", id, assetTag, status);
    fclose(file);
    return 1;
}

void displayItems() {
    FILE *file = fopen(FILE_NAME, "r");
    Item item;

    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nEquipment List\n");
    printf("Index\tID\tAsset Tag\tStatus\n");
    printf("----------------------------------------\n");

    int index = 0;
    while (fscanf(file, "%d %49s %19s", &item.id, item.assetTag, item.status) == 3) {
        printf("%d\t%d\t%s\t\t%s\n", index, item.id, item.assetTag, item.status);
        index++;
    }

    fclose(file);
}

int searchItemById(int id) {
    FILE *file = fopen(FILE_NAME, "r");
    Item item;
    int index = 0;

    if (file == NULL) {
        return -1;
    }

    while (fscanf(file, "%d %49s %19s", &item.id, item.assetTag, item.status) == 3) {
        if (item.id == id) {
            fclose(file);
            return index;
        }
        index++;
    }

    fclose(file);
    return -1;
}

int updateItem(int id, const char newAssetTag[], const char newStatus[]) {
    FILE *file = fopen(FILE_NAME, "r");
    Item items[MAX_ITEMS];
    int count = 0;
    int found = 0;
    int i;

    if (file == NULL) {
        return 0;
    }

    while (count < MAX_ITEMS && fscanf(file, "%d %49s %19s", &items[count].id, items[count].assetTag, items[count].status) == 3) {
        if (items[count].id == id) {
            strcpy(items[count].assetTag, newAssetTag);
            strcpy(items[count].status, newStatus);
            found = 1;
        }
        count++;
    }
    fclose(file);

    if (!found) {
        return 0;
    }

    file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        return 0;
    }

    for (i = 0; i < count; i++) {
        fprintf(file, "%d %s %s\n", items[i].id, items[i].assetTag, items[i].status);
    }
    fclose(file);
    return 1;
}

int main() {
    int position;

    createFileIfMissing();

    /* Delete old file content for a clean demonstration */
    FILE *file = fopen(FILE_NAME, "w");
    if (file != NULL) {
        fclose(file);
    }

    printf("Media Lab Equipment Loan Manager\n");
    printf("--------------------------------\n");

    if (addItem(101, "CAM-104", "A"))
        printf("Item 101 added.\n");
    else
        printf("Item 101 duplicate.\n");

    if (addItem(102, "MIC-205", "L"))
        printf("Item 102 added.\n");
    else
        printf("Item 102 duplicate.\n");

    if (addItem(103, "TRI-301", "A"))
        printf("Item 103 added.\n");
    else
        printf("Item 103 duplicate.\n");

    if (addItem(102, "DUP-999", "A"))
        printf("Duplicate added.\n");
    else
        printf("Duplicate ID refused.\n");

    displayItems();

    position = searchItemById(102);
    if (position != -1) {
        printf("\nItem with ID 102 found at index %d.\n", position);
    } else {
        printf("\nItem with ID 102 not found.\n");
    }

    if (updateItem(102, "MIC-205-UPDATED", "A")) {
        printf("Item 102 updated successfully.\n");
    } else {
        printf("Item 102 not found for update.\n");
    }

    printf("\nUpdated Equipment List\n");
    displayItems();

    return 0;
}
