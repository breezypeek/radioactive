#include <stdio.h>

int main() {
    int balance = 10000;
    int choice;
    int amount;
    printf("1. Withdraw Money\n");
    printf("2. Deposit Money\n");
    printf("3. Check Balance\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter amount to withdraw: ");
        scanf("%d", &amount);

        if (amount > balance) {
            printf("Insufficient balance!\n");
        } else {
            balance = balance - amount;
            printf("Withdrawal successful! Remaining balance: %d\n", balance);
        }
    }
    else if (choice == 2) {
        printf("Enter amount to deposit: ");
        scanf("%d", &amount);

        balance = balance + amount;
        printf("Deposit successful! New balance: %d\n", balance);
    }
    else if (choice == 3) {
        printf("Your balance is: %d\n", balance);
    }
    else {
        printf("Invalid choice! Please enter 1, 2, or 3.\n");
    }

    return 0;
}

