#include <stdio.h>

int main() {
    char zone, ticketType;
    int tickets;
    float ticketPrice = 0.0f, totalCost = 0.0f;

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

    switch (ticketType) {
        case 'N':
            printf("Ticket Type: Standard Entry\n");
            break;
        case 'E':
            printf("Ticket Type: Express Entry\n");
            break;
    }

    totalCost = ticketPrice * tickets;

    printf("Tickets: %d\n", tickets);
    printf("Total Cost: \xC2\xA3%.2f\n", totalCost);

    return 0;
}
