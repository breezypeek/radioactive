#include <stdio.h>

int main() {
    int units;
    int bill = 0;
    printf("Enter units consumed: ");
    scanf("%d", &units);
    if (units > 200) {
        bill += (units - 200) * 5;
        units = 200;
    }
    if (units > 100) {
        bill += (units - 100) * 3;
        units = 100;
    }
    bill += units * 2;
    printf("Total Bill: %d\n", bill);
    return 0;
}
