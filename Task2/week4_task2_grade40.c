#include <stdio.h>

int main() {
    char zone = 'S';
    char ticketType = 'N';
    float ticketPrice = 0.0f;

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
                    printf("Invalid ticket type.\n");
                    return 1;
            }
            printf("Zone: Sharks\n");
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
                    printf("Invalid ticket type.\n");
                    return 1;
            }
            printf("Zone: Reefs\n");
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
                    printf("Invalid ticket type.\n");
                    return 1;
            }
            printf("Zone: Penguins\n");
            break;

        default:
            printf("Invalid zone.\n");
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

    printf("Ticket Price: \xC2\xA3%.2f\n", ticketPrice);

    return 0;
}
