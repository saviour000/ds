#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // Iterate through the array
    {
        int minIndex = i; // Assume the current element is the smallest
        for (int j = i + 1; j < n; j++) // Find the smallest element in the unsorted part
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap the smallest element with the first unsorted element
        swap(&arr[i], &arr[minIndex]);
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main()
{
    int n;

    // Take array size as input
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare an array of size n

    // Take array elements as input
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    // Sort the array using Selection Sort
    selectionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
