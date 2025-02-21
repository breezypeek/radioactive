#include <stdio.h>

void analyzeScores(int scores[], int n) {
    int highest = scores[0], lowest = scores[0], sum = 0;

    for (int i = 0; i < n; i++) {
        if (scores[i] > highest) highest = scores[i];
        if (scores[i] < lowest) lowest = scores[i];
        sum += scores[i];
    }

    float average = (float)sum / n;

    printf("Highest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Average Score: %.2f\n", average);
}

int main() {
    int n;
    printf("Enter number of matches: ");
    scanf("%d", &n);

    int scores[n];
    printf("Enter scores of %d matches: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }

    analyzeScores(scores, n);

    return 0;
}
