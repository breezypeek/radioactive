#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Weather {
    char city[50];
    int temperature;
    int humidity;
};

void saveToFile(struct Weather records[], int n) {
    FILE *file = fopen("weather_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s, %d°C, %d%%\n", records[i].city, records[i].temperature, records[i].humidity);
    }
    fclose(file);
    printf("Data saved in \"weather_data.txt\"\n");
}

void searchCity(struct Weather records[], int n, char city[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(records[i].city, city) == 0) {
            printf("Weather in %s: %d°C, %d%% Humidity\n", records[i].city, records[i].temperature, records[i].humidity);
            return;
        }
    }
    printf("City not found!\n");
}

int main() {
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    getchar(); // Consume the newline character left by scanf

    struct Weather *records = malloc(n * sizeof(struct Weather));
    if (records == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    for (int i = 0; i < n; i++) {
        printf("Enter details for City %d (Name, Temperature, Humidity): ", i + 1);
        fgets(records[i].city, sizeof(records[i].city), stdin);
        records[i].city[strcspn(records[i].city, "\n")] = 0; // Remove newline character

        printf("Enter Temperature: ");
        scanf("%d", &records[i].temperature);

        printf("Enter Humidity: ");
        scanf("%d", &records[i].humidity);

        getchar(); // Consume the newline character left by scanf
    }

    saveToFile(records, n);

    char searchCityName[50];
    printf("\nEnter city name to search: ");
    fgets(searchCityName, sizeof(searchCityName), stdin);
    searchCityName[strcspn(searchCityName, "\n")] = 0; // Remove newline character

    searchCity(records, n, searchCityName);

    free(records); // Free allocated memory
    return 0;
}

