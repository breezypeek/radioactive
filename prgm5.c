#include <stdio.h>

int main() {
    int n, totalTax = 0;
    char vehicle;

    printf("Enter number of vehicles: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter vehicle type (C/T/B/U for Car/Truck/Bike/Bus): ");
        scanf(" %c", &vehicle);
        switch (vehicle)
           {

           case 'C': totalTax += 50; break;
            case 'T': totalTax += 100; break;
            case 'B': totalTax += 20; break;
            case 'U': totalTax += 80; break;
            default: printf("Invalid vehicle type!\n"); break;
        }
    }
    printf("Total Toll Tax %d",totalTax);
}
