#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 2
#define MAX_WAITLIST 5

typedef struct {
    int id;
    char name[50];
} Passenger;

Passenger reservations[MAX_PASSENGERS];
Passenger waitlist[MAX_WAITLIST];
int reservation_count = 0, waitlist_count = 0;

void addReservation(int id, const char *name) {
    if (reservation_count < MAX_PASSENGERS) {
        reservations[reservation_count++] = (Passenger){id, ""};
        strcpy(reservations[reservation_count - 1].name, name);
        printf("Booking Confirmed: Passenger %d (%s)\n", id, name);
    } else if (waitlist_count < MAX_WAITLIST) {
        waitlist[waitlist_count++] = (Passenger){id, ""};
        strcpy(waitlist[waitlist_count - 1].name, name);
        printf("Added to Waiting List: Passenger %d (%s)\n", id, name);
    } else {
        printf("Both reservation and waiting list are full.\n");
    }
}

void processReservation() {
    if (reservation_count > 0) {
        printf("Processing Booking: Passenger %d (%s)\n", reservations[0].id, reservations[0].name);
        for (int i = 1; i < reservation_count; i++) {
            reservations[i - 1] = reservations[i];
        }
        reservation_count--;
        if (waitlist_count > 0) {
            addReservation(waitlist[0].id, waitlist[0].name);
            for (int i = 1; i < waitlist_count; i++) {
                waitlist[i - 1] = waitlist[i];
            }
            waitlist_count--;
        }
    } else {
        printf("No bookings to process.\n");
    }
}

void displayWaitingList() {
    if (waitlist_count > 0) {
        printf("Waiting List: ");
        for (int i = 0; i < waitlist_count; i++) {
            printf("Passenger %d (%s)", waitlist[i].id, waitlist[i].name);
            if (i < waitlist_count - 1) printf(", ");
        }
        printf("\n");
    } else {
        printf("No passengers in the waiting list.\n");
    }
}

int main() {
    addReservation(1, "Alice");
    addReservation(2, "Bob");
    addReservation(3, "Charlie");

    processReservation();
    displayWaitingList();

    processReservation();
    displayWaitingList();

    return 0;
}
