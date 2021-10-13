#include <stdio.h>
#include <stdlib.h>
#include "../helpers/file_reader.h"
#include <string.h>

void day4()
{
    const size_t PASSPORT_ROWS = 1147;
    const size_t PASSPORT_SIZE = 291;
    char* passportFile[1147];
    char* passports[PASSPORT_SIZE];
    fileToArray("inputs/day4.txt", passportFile);

    char nextElement[500] = "";
    size_t passports_index = 0;
    for (size_t i = 0; i < PASSPORT_ROWS; i++) {
        if (strlen(passportFile[i]) > 2) {
            strcat(nextElement, " ");
            strcat(nextElement, passportFile[i]);
            passports[passports_index] = strdup(nextElement);
            // printf("building: %s\n", passports[passports_index]);
        }
        else {
            strcpy(nextElement, "");
            passports_index++;
        }
    }
    // byr (Birth Year)
    // eyr (Expiration Year)
    // ecl (Eye Color)
    // hgt (Height)
    // hcl (Hair Color)
    // iyr (Issue Year)
    // pid (Passport ID)
    // cid (Country ID) - IGNORE
    size_t valid_passport_count = 0;
    for (size_t i = 0; i < PASSPORT_SIZE; i++) {
        int j = 0;
        int valid_field_count = 0;
        while (j < strlen(passports[i])) {
            switch (passports[i][j]) {
            case 'b':
                if (passports[i][j + 1] == 'y' && passports[i][j + 2] == 'r' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                }
                break;
            case 'e':
                if (passports[i][j + 1] == 'y' && passports[i][j + 2] == 'r' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                }
                else if (passports[i][j + 1] == 'c' && passports[i][j + 2] == 'l' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                }
                break;
            case 'h':
                if (passports[i][j + 1] == 'g' && passports[i][j + 2] == 't' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                }
                else if (passports[i][j + 1] == 'c' && passports[i][j + 2] == 'l' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                }
                break;
            case 'i':
                if (passports[i][j + 1] == 'y' && passports[i][j + 2] == 'r' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                }
                break;
            case 'p':
                if (passports[i][j + 1] == 'i' && passports[i][j + 2] == 'd' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                }
                break;
            }
            j++;
            if(valid_field_count == 7) {
                valid_passport_count++;
                j = strlen(passports[i]);
            }
        }
    }
    printf("%ld", valid_passport_count);
}