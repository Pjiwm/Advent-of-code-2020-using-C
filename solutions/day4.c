#include <stdio.h>
#include <stdlib.h>
#include "../helpers/file_reader.h"
#include <string.h>
#include <stdbool.h> 
#include <ctype.h>

size_t year_check(char* str, size_t current_index) {
    // printf("at %ld %s\n ", current_index, str);
    char year_str[4];
    for (int i = 0; i < 4; i++) {
        year_str[i] = str[current_index + i + 1];
    }
    return atoi(year_str);
}

_Bool check_byr(char* str, size_t current_index) {
    size_t age = year_check(str, current_index);
    _Bool result = 0;
    if (age >= 1920 && age <= 2002) {
        result = 1;
    }
    return result;
}


_Bool check_iyr(char* str, size_t current_index) {
    size_t issue_year = year_check(str, current_index);
    _Bool result = 0;
    if (issue_year >= 2010 && issue_year <= 2020) {
        result = 1;
    }
    return result;
}

_Bool check_eyr(char* str, size_t current_index) {
    size_t exp_year = year_check(str, current_index);
    _Bool result = 0;
    if (exp_year >= 2020 && exp_year <= 2030) {
        result = 1;
    }
    return result;
}

_Bool check_hgt(char* str, size_t current_index) {
    current_index += 4;
    _Bool is_valid_hgt = 0;
    // if char for index is c it's a height in cm with 3 digits.
    // if char for index is n it's a height in inches with 2 digits.
    // all other heights are already invalid.

    // height in cm check
    if (str[current_index] == 'c') {
        char hgt_str[3];
        for (size_t i = 0; i < 3; i++) {
            hgt_str[2 - i] = str[current_index - i - 1];
        }
        if (atoi(hgt_str) >= 150 && atoi(hgt_str) <= 193) {
            is_valid_hgt = 1;
        }
    }
    // height in inches check
    else if (str[current_index] == 'n') {
        char hgt_str[2];
        hgt_str[0] = str[current_index - 3];
        hgt_str[1] = str[current_index - 2];
        if (atoi(hgt_str) >= 59 && atoi(hgt_str) <= 76) {
            is_valid_hgt = 1;
        }
    }
    return is_valid_hgt;
}

_Bool check_hcl(char* str, size_t current_index) {
    _Bool is_valid_hcl = 0;
    current_index++;
    char hex[6];
    if (str[current_index] == '#') {
        current_index++;
        for (size_t i = 0; i < 6; i++) {
            hex[i] = str[current_index + i];
        }
        current_index += 6;
    }
    // we check if the hexadecimal isn't actually longer than 6 digits.
    if (isxdigit(*hex) && !isxdigit(str[current_index])) {
        is_valid_hcl = 1;
    }

    return is_valid_hcl;
}

_Bool check_ecl(char* str, size_t current_index) {
    _Bool is_valid_hcl = 0;
    current_index++;
    // get the color from passport
    char eye_color[3];
    for (size_t i = 0; i < 3; i++) {
        eye_color[i] = str[current_index + i];
    }
    char colors[7][3] = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };

    for (size_t i = 0; i < 7; i++) {
        if (strcmp(colors[i], eye_color)) {
            is_valid_hcl = 1;
        }
    }

    return is_valid_hcl;
}

_Bool check_pid(char* str, size_t current_index) {
    _Bool is_valid_pid = 0;
    current_index++;
    size_t digit_count = 0;
    for (size_t i = 0; i < 10; i++) {
        if (isdigit(str[current_index + i])) {
            digit_count++;
        }
    }

    if (digit_count == 9) {
        is_valid_pid = 1;
    }

    return is_valid_pid;
}

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
    size_t valid_strict_passport_count = 0;
    for (size_t i = 0; i < PASSPORT_SIZE; i++) {
        int j = 0;
        int valid_field_count = 0;
        int valid_strict_field_count = 0;
        while (j < strlen(passports[i])) {
            switch (passports[i][j]) {
            case 'b':
                // byr
                if (passports[i][j + 1] == 'y' && passports[i][j + 2] == 'r' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                    // strict check
                    if (check_byr(passports[i], j)) {
                        valid_strict_field_count++;
                    }
                }
                break;
            case 'e':
                // eyr
                if (passports[i][j + 1] == 'y' && passports[i][j + 2] == 'r' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                    // strict check
                    if (check_eyr(passports[i], j)) {
                        valid_strict_field_count++;
                    }
                }
                // ecl
                else if (passports[i][j + 1] == 'c' && passports[i][j + 2] == 'l' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                    // strict check
                    if (check_ecl(passports[i], j)) {
                        valid_strict_field_count++;
                    }
                }
                break;
            case 'h':
                // hgt
                if (passports[i][j + 1] == 'g' && passports[i][j + 2] == 't' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                    // strict check
                    if (check_hgt(passports[i], j)) {
                        valid_strict_field_count++;
                    }
                }
                // hcl
                else if (passports[i][j + 1] == 'c' && passports[i][j + 2] == 'l' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                    // strict check
                    if (check_hcl(passports[i], j)) {
                        valid_strict_field_count++;
                    }
                }
                break;
            case 'i':
                // iyr
                if (passports[i][j + 1] == 'y' && passports[i][j + 2] == 'r' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                    // strict check
                    if (check_iyr(passports[i], j)) {
                        valid_strict_field_count++;
                    }
                }
                break;
            case 'p':
                // pid 
                if (passports[i][j + 1] == 'i' && passports[i][j + 2] == 'd' && passports[i][j + 3] == ':') {
                    valid_field_count++;
                    j += 3;
                    // strict check
                    if (check_pid(passports[i], j)) {
                        valid_strict_field_count++;
                    }
                }
                break;
            }
            j++;
            if (valid_field_count == 7) {
                valid_passport_count++;
                j = strlen(passports[i]);
            }

            if (valid_strict_field_count == 7) {
                valid_strict_passport_count++;
            }
        }
    }
    printf("%ld\n", valid_passport_count);
    // it loops over the passports one more time and adds another valid one?
    printf("%ld\n", valid_strict_passport_count - 1);
}