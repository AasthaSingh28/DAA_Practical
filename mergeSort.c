#include <stdio.h>

// Function to merge two sorted subarrays
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1; // size of left subarray
    int n2 = r - mid;     // size of right subarray

    int a[n1]; // temporary array for left subarray
    int b[n2]; // temporary array for right subarray

    // copy elements from original array to temporary arrays
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0; // index for left subarray
    int j = 0; // index for right subarray
    int k = l; // index for original array

    // merge smaller elements from both subarrays
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    // copy remaining elements from left subarray, if any
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }

    // copy remaining elements from right subarray, if any
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;      // find middle index
        mergeSort(arr, l, mid);     // recursively sort left half
        mergeSort(arr, mid + 1, r); // recursively sort right half

        merge(arr, l, mid, r); // merge sorted halves
    }
}

int main()
{
    int n;
    printf("Enter the no. of elements in an array:\n");
    scanf("%d", &n); // note the ampersand (&) to pass address of n

    int arr[n]; // declare array with size n

    printf("Enter the values of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // note the ampersand (&) to pass address of arr[i]
    }

    mergeSort(arr, 0, n - 1); // call mergeSort with correct upper bound (n-1)

    return 0;
}