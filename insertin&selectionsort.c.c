#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000
void generateRandomNumbersToFile(const char *filename) {
	int i;
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    srand(time(NULL)); // Seed RNG

    for ( i = 0; i < SIZE; i++) {
        int num = rand();
        fprintf(file, "%d\n", num);
    }

    fclose(file);
    printf("Successfully wrote %d random numbers to %s\n", SIZE, filename);
}

void insertionSort(int arr[], int n) {
	int i;
    for ( i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
	int i,j,temp;
    for ( i = 0; i < n - 1; i++) {
        int min_idx = i;
        for ( j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap
         temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[SIZE];
    int choice,i;
    FILE *inputFile, *outputFile;

    generateRandomNumbersToFile("C:\\Users\\autocad\\Documents\\input.txt");

    inputFile = fopen("C:\\Users\\autocad\\Documents\\input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    for ( i = 0; i < SIZE; i++) {
        if (fscanf(inputFile, "%d", &arr[i]) != 1) {
            printf("Error reading data from file.\n");
            fclose(inputFile);
            return 1;
        }
    }
    fclose(inputFile);

    printf("Choose sorting method:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        insertionSort(arr, SIZE);
        printf("Sorted using Insertion Sort.\n");
    } else if (choice == 2) {
        selectionSort(arr, SIZE);
        printf("Sorted using Selection Sort.\n");
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    outputFile = fopen("C:\\Users\\autocad\\Documents\\output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (i = 0; i < SIZE; i++) {
        fprintf(outputFile, "%d\n", arr[i]);
    }
    fclose(outputFile);

    printf("Sorting complete. Check output.txt for results.\n");
    return 0;
}

