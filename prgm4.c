#include <stdio.h>

int main() {
    int age, salary;
    char condition;
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Any Pre-existing Condition? (y/n): ");
    scanf(" %c", &condition);
    printf("Enter Monthly Salary: ");
    scanf("%d", &salary);
    if (age >= 18 && age <= 60 && condition == 'n' && salary >= 25000) {
        printf("Eligible for Medical Insurance.\n");
    } else {
        printf("Not Eligible for Medical Insurance.\n");
    }
    return 0;
}

