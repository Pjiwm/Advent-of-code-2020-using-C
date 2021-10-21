#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "../helpers/file_reader.h"
#include "../helpers/linked_list.h"
size_t answer_count(char* str) {
    size_t count = 0;

    char* answered_questions = (char*)malloc(26 * sizeof(char));
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

    char* answered_questions = (char*)malloc(26 * sizeof(char));
    for (size_t i = 0; i < strlen(str); i++) {
        if (isalpha(str[i]) && strchr(answered_questions, str[i]) == NULL) {
            answered_questions[answer_index] = str[i];
            answer_index++;
        }
    }

    String_Node* root = NULL;
    char* row = (char*)malloc(26 * sizeof(char));
    size_t row_index = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] != '\n') {
            row[row_index++] = str[i];
        }
        else {
            str_insert_tail(&root, strdup(row));
            row_index = 0;
            row = (char*)malloc(26 * sizeof(char));
        }
    }

    // does not loop through last row so we add it manually after the loop.
    // str_insert_tail(&root, strdup(row));
    for (String_Node* curr = root; curr != NULL; curr = curr->next) {
    }
    for (String_Node* curr = root; curr != NULL; curr = curr->next) {
        for (size_t i = 0; i < strlen(answered_questions); i++) {
            _Bool has_answer = 0;
            for (size_t j = 0; j < strlen(curr->value); j++) {
                if (curr->value[j] == answered_questions[i]) {
                    has_answer = 1;
                }
            }
            if (!has_answer) {
                answered_questions[i] = '0';
            }
        }
    }
    str_deallocate(&root);

    size_t remaining_answers = 0;
    for (size_t i = 0; i < strlen(answered_questions); i++) {
        if (isalpha(answered_questions[i])) {
            remaining_answers++;
        }
    }

    return remaining_answers;
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

    size_t sum_part1 = 0;
    size_t sum_part2 = 0;
    for (size_t i = 0; i < sizeof(groups) / sizeof(groups[0]); i++) {
        sum_part1 += answer_count(groups[i]);
        sum_part2 += answer_count_part2(groups[i]);
    }
    printf("day6:\n");
    printf("%ld\n", sum_part1);
    printf("%ld\n", sum_part2);

    free(*group_file);
    free(*groups);
}
