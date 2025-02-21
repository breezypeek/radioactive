#include <stdio.h>

int main() {
    int students, i;
    int marks[100];
    printf("Enter number of students ");
    scanf("%d",&students);
    printf("Enter marks ");
    for (i = 0; i < students; i++) {
        scanf("%d",&marks[i]);
    }
    for (i=0;i<students;i++) {
        printf("Student %d", i+1);
        if (marks[i]>=90&&marks[i]<=100) {
            printf("Grade A\n");
        } else if (marks[i]>= 80) {
            printf("Grade B\n");
        } else if (marks[i] >= 70) {
            printf("Grade C\n");
        } else if (marks[i] >= 60) {
            printf("Grade D\n");
        } else {
            printf("Grade F\n");
        }
    }
    return 0;
}
