
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge.h" // Include the header file

int main()
{
    // Your main program logic goes here

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
