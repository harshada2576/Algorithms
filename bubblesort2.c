#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void fileMake(int n) {
    int i;
    FILE* fptr = fopen("randnum.txt", "w");
    for (i = 0; i < n; i++) {
        fprintf(fptr, "%d\n", rand() );  // Generate random numbers between 0 and 99999
    }
    fclose(fptr);
}

void readFromFile(int arr[], int *count) {
    FILE *file = fopen("randnum.txt", "r");
    *count = 0;
    while (fscanf(file, "%d", &arr[*count]) != EOF) {
        (*count)++;
    }
    fclose(file);
}

void writeNumbersToFile(int arr[], int count) {
    int i;
    FILE *file = fopen("sortednum.txt", "w");
    for (i = 0; i < count; i++) {
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);
}

int main() {
    int n;
    printf("Enter number of terms : ");
    scanf("%d", &n);

    

    // Allocate memory for the array
    int *a = (int *)malloc(n * sizeof(int));

    fileMake(n);

    readFromFile(a, &n);

    bubbleSort(a, n);

    writeNumbersToFile(a, n);

    printf("Sorted numbers written to sortednum.txt successfully.\n");

    free(a);

    return 0;
}
