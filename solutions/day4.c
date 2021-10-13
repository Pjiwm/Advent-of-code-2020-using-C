#include <stdio.h>
#include <stdlib.h>
#include "../helpers/file_reader.h"
#include <string.h>

void day4()
{
    const size_t PASSPORT_ROWS = 1147;
    char* passportFile[1147];
    char* passports[1000];
    fileToArray("inputs/day4.txt", passportFile);

    char nextElement[500] = "";
    size_t passports_index = 0;
    for (size_t i = 0; i < PASSPORT_ROWS; i++) {
        if (strlen(passportFile[i]) > 2) {
            strcat(nextElement, " ");
            strcat(nextElement, passportFile[i]);
            passports[passports_index] = strdup(nextElement);
            strcpy(nextElement, "");
        } else {
            passports_index++;
        }
    }
    printf("0: %s \n", passports[0]);
    printf("1:%s \n", passports[1]);
    printf("2:%s \n", passports[2]);
    printf("3:%s \n", passports[3]);
    printf("4:%s \n", passports[4]);
    printf("5:%s \n", passports[5]);

    // for (int i = 0; i < sizeof(passports)/sizeof(passports[0]); i++) {
    //     printf("%s \n", passports[4]);
    // }
}