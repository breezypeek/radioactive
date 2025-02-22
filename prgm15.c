#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient {
    int id;
    char name[50];
    struct Patient *prev;
    struct Patient *next;
} Patient;

Patient *head = NULL;
Patient *tail = NULL;

void addPatient(int id, const char *name) {
    Patient *new_patient = (Patient *)malloc(sizeof(Patient));
    new_patient->id = id;
    strcpy(new_patient->name, name);
    new_patient->prev = tail;
    new_patient->next = NULL;

    if (tail) {
        tail->next = new_patient;
    } else {
        head = new_patient;
    }
    tail = new_patient;

    printf("New Patient Admitted: %s (ID %d)\n", name, id);
}

void dischargePatient(int id) {
    Patient *current = head;
    while (current) {
        if (current->id == id) {
            printf("Discharging: %s\n", current->name);
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Patient with ID %d not found.\n", id);
}

void displayPatients() {
    Patient *current = head;
    if (!current) {
        printf("No patients in the system.\n");
        return;
    }
    printf("Remaining Patients: ");
    while (current) {
        printf("%s (ID %d)", current->name, current->id);
        if (current->next) {
            printf(" ↔ ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    addPatient(201, "John");
    addPatient(202, "Mary");
    addPatient(203, "David");

    dischargePatient(202);
    displayPatients();

    return 0;
}
