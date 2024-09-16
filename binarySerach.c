#include <stdio.h>

// Function to perform binary search
void binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1; // subtract 1 to avoid out-of-bounds access

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            printf("Element found at index %d\n", mid);
            return;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Element not found in the array\n");
}

int main()
{
    int n;
    printf("Enter the no. of elements of an array:\n");
    scanf("%d", &n); // note the ampersand (&) to pass address of n

    int arr[n]; // declare array with size n

    printf("Enter the values of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // note the ampersand (&) to pass address of arr[i]
    }

    printf("Enter the number you want to search:\n");
    int key;
    scanf("%d", &key); // note the ampersand (&) to pass address of key

    binarySearch(arr, n, key);

    return 0;
}