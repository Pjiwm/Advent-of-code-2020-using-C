#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_to_array(char *fileName, char *result[])
{
    FILE *fPointer = fopen(fileName, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int index = 0;
    
    char passport[] = "";

    while ((read = getline(&line, &len, fPointer)) != -1)
    {
        result[index] = strdup(line);
        index++;
    }

    fclose(fPointer);
    if (line)
    {
        free(line);
    }
}

void printArr(char *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", arr[i]);
    }
}