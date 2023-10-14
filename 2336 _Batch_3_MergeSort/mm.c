#include <stdio.h>  //Standard input/output functions for file operations.
#include <stdlib.h> //Standard library functions like memory allocation.
#include <string.h> //String manipulation functions.

// Structure to represent data in the format: count,word
struct Data
{
    int count;
    char word[50]; // Adjust the size as needed for your data
};

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

int main()
{
    // Open the input file
    FILE *inputFile = fopen("inputQS.csv", "r");
    if (inputFile == NULL)
    {
        perror("Error opening input file");
        return 1;
    }

    // Read the data from the input file into an array
    struct Data input_data[1000]; // Assuming a maximum of 1000 entries
    int count = 0;
    char line[100]; // Adjust the size as needed for your data

    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        sscanf(line, "%d,%s", &input_data[count].count, input_data[count].word);
        count++;
    }
    fclose(inputFile);

    // Perform merge sort
    merge_sort(input_data, 0, count - 1);

    // Open the output file
    FILE *outputFile = fopen("output.csv", "w");
    if (outputFile == NULL)
    {
        perror("Error opening output file");
        return 1;
    }

    // Write the sorted data to the output file
    for (int i = 0; i < count; i++)
    {
        fprintf(outputFile, "%d,%s\n", input_data[i].count, input_data[i].word);
    }
    fclose(outputFile);

    printf("Data has been sorted and written to 'output.txt'.\n");

    return 0;
}