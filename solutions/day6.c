#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../helpers/file_reader.h"
// TODO fix segmentation fault
size_t answer_count(char* str) {
    size_t count = 0;

    char* answered_questions = (char *)malloc(26 * sizeof(char));
    for (size_t i = 0; i < strlen(str); i++) {
        if (isalpha(str[i]) && strchr(answered_questions, str[i]) == NULL) {
            answered_questions[count] = str[i];
            count++;
        }
    }

    answered_questions = "";
    return count;
}
// answer count should go up if letter appears on each row.
size_t answer_count_part2(char* str) {
    size_t answer_index = 0;

    char* answered_questions = (char *)malloc(26 * sizeof(char));
    for (size_t i = 0; i < strlen(str); i++) {
        if (isalpha(str[i]) && strchr(answered_questions, str[i]) == NULL) {
            answered_questions[answer_index] = str[i];
            answer_index++;
        }
    }

    char individual_answers[15][26];

    size_t rows = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] != '\n') {
            individual_answers[rows][i] = str[i];
        } else {
            rows++;
        }
    }
    // printf("%s\n", individual_answers[0]);
    // printf("%s\n", individual_answers[1]);
    // printf("%s\n", individual_answers[2]);
    for (size_t i = 0; i < answer_index; i++) {
        answered_questions[i] = '\0';
    }
    answered_questions = "";
    return 0;
}

void day6() {
    const size_t FILE_ROWS = 2042;
    const size_t GROUP_COUNT = 454;
    char* group_file[FILE_ROWS];
    char* groups[GROUP_COUNT];
    file_to_array("inputs/day6.txt", group_file);

    char nextElement[250] = "";
    size_t passports_index = 0;
    for (size_t i = 0; i < FILE_ROWS; i++) {
        if (group_file[i][0] != '\n') {
            strcat(nextElement, " ");
            strcat(nextElement, group_file[i]);
            groups[passports_index] = strdup(nextElement);

        }
        else {
            strcpy(nextElement, "");
            passports_index++;
        }
    }

    size_t sum = 0;
    for (size_t i = 0; i < sizeof(groups) / sizeof(groups[0]); i++) {
        sum += answer_count(groups[i]);
    }
    printf("day6:\n");
    printf("%ld\n", sum);
    answer_count_part2("groups[0]\ndeez\nnuts");
    free(*group_file);
    free(*groups);
}
