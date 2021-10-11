#include <stdio.h>
#include <stdlib.h>
#include "../helpers/file_reader.h"
#include <string.h>

void day4()
{
    int PASSPORT_ROWS = 1147;
    char *passportFile[4000];
    fileToArray("inputs/day4.txt", passportFile);

    // char *nextElement = "";
    char nextElement[] = "";
    // char * nextElementp = &nextElement;
    // for (int i = 0; i < PASSPORT_ROWS; i++)
    // {
    //     if (passportFile[i][0] != '\n')
    //     {
    //         strcat(nextElement, " ");
    //         strcat(nextElement, passportFile[i]);
    //         printf("%s", nextElement);
    //     }
    // }'
    for(int i = 0; i < PASSPORT_ROWS; i++) {
        printf("%s", passportFile[i]);
    }
}