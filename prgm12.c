#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Order {
    int orderID;
    char customerName[50];
    char product[50];
    int amount;
};

void saveToFile(struct Order records[], int n) {
    FILE *file = fopen("orders.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d, %s, %s, ₹%d\n", records[i].orderID, records[i].customerName, records[i].product, records[i].amount);
    }
    fclose(file);
    printf("Record saved in \"orders.txt\"\n");
}

void searchOrder(struct Order records[], int n, int orderID) {
    for (int i = 0; i < n; i++) {
        if (records[i].orderID == orderID) {
            printf("Order Found: %s - %s - ₹%d\n", records[i].customerName, records[i].product, records[i].amount);
            return;
        }
    }
    printf("Order not found!\n");
}

int main() {
    int n;
    printf("Enter number of orders: ");
    scanf("%d", &n);
    getchar();

    struct Order records[n];

    for (int i = 0; i < n; i++) {
        printf("Enter details for Order %d (Order ID, Customer Name, Product, Amount): ", i + 1);
        scanf("%d", &records[i].orderID);
        getchar();
        fgets(records[i].customerName, 50, stdin);
        records[i].customerName[strcspn(records[i].customerName, "\n")] = 0;
        fgets(records[i].product, 50, stdin);
        records[i].product[strcspn(records[i].product, "\n")] = 0;
        scanf("%d", &records[i].amount);
        getchar();
    }

    saveToFile(records, n);

    int searchOrderID;
    printf("\nEnter Order ID to search: ");
    scanf("%d", &searchOrderID);

    searchOrder(records, n, searchOrderID);

    return 0;
}

