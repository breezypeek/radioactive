#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    char course[50];
    int marks;
};

void saveToFile(struct Student *students, int n) {
    FILE *file = fopen("students.dat", "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(students, sizeof(struct Student), n, file);
    fclose(file);
    printf("Record saved in \"students.dat\"\n");
}

void searchStudent(int rollNo) {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    struct Student s;
    while (fread(&s, sizeof(struct Student), 1, file)) {
        if (s.rollNo == rollNo) {
            printf("Student Found: %s, %s, Marks: %d\n", s.name, s.course, s.marks);
            fclose(file);
            return;
        }
    }
    printf("Student not found!\n");
    fclose(file);
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter details for Student %d (Roll No, Name, Course, Marks): ", i + 1);
        scanf("%d", &students[i].rollNo);
        getchar(); // Consume newline
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0;
        fgets(students[i].course, 50, stdin);
        students[i].course[strcspn(students[i].course, "\n")] = 0;
        scanf("%d", &students[i].marks);
    }

    saveToFile(students, n);
    free(students);

    int rollNo;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &rollNo);
    searchStudent(rollNo);

    return 0;
}

