#include <stdio.h>
#include <string.h>

int countPatternOccurrences(char dna[], char pattern[]) {
    int count = 0;
    int dnaLength = strlen(dna);
    int patternLength = strlen(pattern);

    for (int i = 0; i <= dnaLength - patternLength; i++) {
        if (strncmp(&dna[i], pattern, patternLength) == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    char dna[100], pattern[20];


    printf("Enter DNA Sequence: ");
    scanf("%s", dna);
    printf("Enter pattern to search: ");
    scanf("%s", pattern);
    int occurrences = countPatternOccurrences(dna, pattern);
    printf("Pattern found %d time(s) in the DNA sequence.\n", occurrences);

    return 0;
}

