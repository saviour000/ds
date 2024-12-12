#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on a specific digit (represented by exp)
void countingSort(int arr[], int n, int exp) {
    int output[n];  // Output array to store sorted numbers
    int count[10] = {0};  // Count array for digits 0-9

    // Count the occurrences of each digit in the input array
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Modify the count array to store the cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing elements at the correct position
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted output array to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to implement Radix Sort
void radixSort(int arr[], int n) {
    // Get the maximum number to know the number of digits
    int max = getMax(arr, n);

    // Perform counting sort for every digit. The exp is 10^i where i is the current digit number.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    // Input size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);

    // Apply Radix Sort
    radixSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}