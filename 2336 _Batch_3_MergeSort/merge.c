#include <stdio.h>  //Standard input/output functions for file operations.
#include <stdlib.h> //Standard library functions like memory allocation.
#include <string.h> //String manipulation functions.
#include "merge.h"

// Function to merge two subarrays
void merge(struct Data arr[], int left, int mid, int right)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;

    // Create temporary arrays
    struct Data left_subarray[left_size];
    struct Data right_subarray[right_size];

    // Copy data to temp arrays
    for (int i = 0; i < left_size; i++)
        left_subarray[i] = arr[left + i];
    for (int j = 0; j < right_size; j++)
        right_subarray[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[]
    int i = 0, j = 0, k = left;
    while (i < left_size && j < right_size)
    {
        if (left_subarray[i].count <= right_subarray[j].count)
        {
            arr[k] = left_subarray[i];
            i++;
        }
        else
        {
            arr[k] = right_subarray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_subarray[], if any
    while (i < left_size)
    {
        arr[k] = left_subarray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_subarray[], if any
    while (j < right_size)
    {
        arr[k] = right_subarray[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void merge_sort(struct Data arr[], int left, int right)
{
    if (left < right) // ensures that there are at least two elements to sor
    {
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
