#include <stdio.h>
#include <stdlib.h>
#include "../helpers/file_reader.h"
#include <string.h>

void set_attributes(int* num1, int* num2, char* letter_match, char* password_rules) {
    char* rules_dup = strdup(password_rules);
    strtok(rules_dup, " ");
    *letter_match = strtok(NULL, " ")[0];
    *num1 = atoi(strtok(rules_dup, "-"));
    *num2 = atoi(strtok(NULL, "-"));
}

size_t part1(char* password_rules[], char* passwords[], size_t LENGTH) {
    size_t valid_passport_count = 0;

    for (size_t i = 0; i < LENGTH; i++) {
        int min;
        int max;
        char letter_match;
        set_attributes(&min, &max, &letter_match, password_rules[i]);

        size_t match_count = 0;
        for (size_t j = 0; j < strlen(passwords[i]); j++) {
            if (passwords[i][j] == letter_match) {
                match_count++;
            }
        }
        if (match_count >= min && match_count <= max) {
            valid_passport_count++;
        }
    }
    return valid_passport_count;
}

size_t part2(char* password_rules[], char* passwords[], size_t LENGTH) {
    size_t valid_passport_count = 0;
    for (size_t i = 0; i < LENGTH; i++) {
        int index1;
        int index2;
        char letter_match;
        set_attributes(&index1, &index2, &letter_match, password_rules[i]);

        if (passwords[i][index1] == letter_match ^ passwords[i][index2] == letter_match) {
            valid_passport_count++;
        }

    }
    return valid_passport_count;
}

void day2() {

    const size_t LENGTH = 1000;
    char* lines[LENGTH];
    file_to_array("inputs/day2.txt", lines);

    char* password_rules[LENGTH];
    char* passwords[LENGTH];
    for (size_t i = 0; i < LENGTH; i++) {
        password_rules[i] = strtok(lines[i], ":");
        passwords[i] = strtok(NULL, ":");
    }

    printf("day 2:\n");
    printf("%ld\n", part1(password_rules, passwords, LENGTH));
    printf("%ld\n", part2(password_rules, passwords, LENGTH));
    for (size_t i = 0; i < LENGTH; i++) {
        free(lines[i]);
    }
}