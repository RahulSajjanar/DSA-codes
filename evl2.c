#include <stdio.h>
#include <time.h>
#define ARRAY_SIZE 20

void array_multiply(int arr1[], int arr2[], int result[], int size) {
    int i;
    for (i = 0; i < size - 4; i += 4) {
        result[i] = arr1[i] * arr2[i];
        result[i + 1] = arr1[i + 1] * arr2[i + 1];
        result[i + 2] = arr1[i + 2] * arr2[i + 2];
        result[i + 3] = arr1[i + 3] * arr2[i + 3];
    }

    for (i=0; i < size; i++) {
        result[i] = arr1[i] * arr2[i];
    }
}
void array_print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[ARRAY_SIZE];
    int arr2[ARRAY_SIZE];
    int result[ARRAY_SIZE];
    clock_t start = clock(); // Start measuring the time

    // Initialize arrays with values from 1 to ARRAY_SIZE
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr1[i] = i + 1;
        arr2[i] = i + 1;
    }
printf("Array 1: ");
    array_print(arr1, ARRAY_SIZE);

    printf("Array 2: ");
    array_print(arr2, ARRAY_SIZE);


    array_multiply(arr1, arr2, result, ARRAY_SIZE);
    printf("Result Array: ");
    array_print(result, ARRAY_SIZE);
    clock_t end = clock(); // Stop measuring the time

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time: %f seconds\n", cpu_time_used);

    return 0;
}
