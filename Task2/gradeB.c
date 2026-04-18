#include <stdio.h>

int main() {
    char zone, ticketType, audioGuide;
    int tickets;
    float ticketPrice = 0.0f;
    float totalBeforeDiscount, discountAmount = 0.0f;
    float addOnCost = 0.0f, finalTotal;

    printf("City Aquarium Ticketing System\n");
    printf("------------------------------\n");

    printf("Enter zone (S = Sharks, R = Reefs, P = Penguins): ");
    scanf(" %c", &zone);

    printf("Enter ticket type (N = Standard Entry, E = Express Entry): ");
    scanf(" %c", &ticketType);

    printf("Enter number of tickets: ");
    scanf("%d", &tickets);

    if (tickets <= 0) {
        printf("Error: Number of tickets must be greater than 0.\n");
        return 1;
    }

    switch (zone) {
        case 'S':
            switch (ticketType) {
                case 'N':
                    ticketPrice = 22.00f;
                    break;
                case 'E':
                    ticketPrice = 32.00f;
                    break;
                default:
                    printf("Error: Invalid ticket type.\n");
                    return 1;
            }
            printf("\nZone: Sharks\n");
            break;

        case 'R':
            switch (ticketType) {
                case 'N':
                    ticketPrice = 18.00f;
                    break;
                case 'E':
                    ticketPrice = 28.00f;
                    break;
                default:
                    printf("Error: Invalid ticket type.\n");
                    return 1;
            }
            printf("\nZone: Reefs\n");
            break;

        case 'P':
            switch (ticketType) {
                case 'N':
                    ticketPrice = 16.00f;
                    break;
                case 'E':
                    ticketPrice = 26.00f;
                    break;
                default:
                    printf("Error: Invalid ticket type.\n");
                    return 1;
            }
            printf("\nZone: Penguins\n");
            break;

        default:
            printf("Error: Invalid zone.\n");
            return 1;
    }

    printf("Would you like an Audio Guide? (y/n): ");
    scanf(" %c", &audioGuide);

    if (audioGuide != 'y' && audioGuide != 'Y' && audioGuide != 'n' && audioGuide != 'N') {
        printf("Error: Invalid choice for Audio Guide.\n");
        return 1;
    }

    switch (ticketType) {
        case 'N':
            printf("Ticket Type: Standard Entry\n");
            break;
        case 'E':
            printf("Ticket Type: Express Entry\n");
            break;
    }

    totalBeforeDiscount = ticketPrice * tickets;

    if (tickets > 5) {
        discountAmount = totalBeforeDiscount * 0.15f;
    }

    if (audioGuide == 'y' || audioGuide == 'Y') {
        addOnCost = 4.50f * tickets;
    }

    finalTotal = totalBeforeDiscount - discountAmount + addOnCost;

    printf("Tickets: %d\n", tickets);
    printf("Total Before Discount: \xC2\xA3%.2f\n", totalBeforeDiscount);
    printf("Bulk Discount (15%%): -\xC2\xA3%.2f\n", discountAmount);
    printf("Add-on Cost: \xC2\xA3%.2f\n", addOnCost);
    printf("Final Total: \xC2\xA3%.2f\n", finalTotal);

    return 0;
}
