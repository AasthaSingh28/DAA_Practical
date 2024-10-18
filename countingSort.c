#include <stdio.h>
#include <stdlib.h>

void countSort(int arr[], int n, int k) {
    int output[n];
    int count[k];

    // Initialize count array
    for (int i = 0; i < k; i++) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Change count[i] so that it contains the actual position of this element in output[]
    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {11, 2, 3, 1, 2, 3, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 12; // The range of input values (0 to k-1)
    printf("Before sorting array elements are - \n");
    printArr(arr, n);
    countSort(arr, n, k);
    printf("\nAfter sorting array elements are - \n");
    printArr(arr, n);
    return 0;
}
