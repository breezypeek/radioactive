#include <stdio.h>

int main() {
    int n, salary;
    int low=0, middle=0, high=0;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    printf("Enter salaries: ");
    for (int i=0;i<n;i++) {
        scanf("%d",&salary);
        if (salary<30000)
            low++;
        else if (salary<=70000)
            middle++;
        else
            high++;
    }
    printf("Low Income: %d\n", low);
    printf("Middle Income: %d\n", middle);
    printf("High Income: %d\n", high);
    return 0;
}

