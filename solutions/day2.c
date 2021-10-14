#include <stdio.h>
#include <stdlib.h>
#include "../helpers/file_reader.h"
#include <string.h>

size_t part1(char* password_rules[], char* passwords[], size_t LENGTH) {
    size_t valid_passport_count = 0;

    for (size_t i = 0; i < LENGTH; i++) {
        strtok(password_rules[i], " ");
        char letter_match = strtok(NULL, " ")[0];
        int min = atoi(strtok(password_rules[i], "-"));
        int max = atoi(strtok(NULL, "-"));

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

void day2() {

    const size_t LENGTH = 1000;
    char* lines[LENGTH];
    fileToArray("inputs/day2.txt", lines);

    char* password_rules[LENGTH];
    char* passwords[LENGTH];
    for (size_t i = 0; i < LENGTH; i++) {
        password_rules[i] = strtok(lines[i], ":");
        passwords[i] = strtok(NULL, ":");
    }
    // for (int i = 0; i < LENGTH; i++) {
    //     printf("%s ", password_rules[i]);
    //     printf("%s\n", passwords[i]);
    // }

    printf("day 2:\n");
    printf("%ld\n", part1(password_rules, passwords, LENGTH));
}