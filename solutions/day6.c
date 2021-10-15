#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../helpers/file_reader.h"

size_t question_count(char* str) {
    size_t count = 0;

    char * answered_questions;
    for (size_t i = 0; i < strlen(str); i++) {
        if (isalpha(str[i]) && strchr(answered_questions, str[i]) == NULL) {
            answered_questions[count] = str[i];
            count++;
        }
    }
    for(size_t i = 0; i < count; i++) {
        answered_questions[i] =  '\0';
    }
    return count;
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
    for (size_t i = 0; i < GROUP_COUNT; i++) {
        sum += question_count(groups[i]);
    }
    printf("day6:\n");
    printf("%ld\n", sum);

}