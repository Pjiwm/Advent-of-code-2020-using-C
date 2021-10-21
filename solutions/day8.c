#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../helpers/file_reader.h"
#include "../helpers/linked_list.h"

int accumulator = 0;
int instruction_manager(char* _instruction, _Bool* _has_no_repeats) {
    char* instruction = strdup(_instruction);
    char* cmd = strtok(strdup(instruction), " ");
    int amount = atoi(strtok(NULL, " "));
    printf("am: %d cmd: %s", amount, cmd);
    if (strcmp(cmd, " jump")) {
        return amount;
    }
    else if (strcmp(cmd, " acc")) {
        accumulator += amount;
        return 1;
    }
    else if (strcmp(cmd, " nop")) {
        return 1;
    }
    else {
        printf("Unknown command: %s\n", cmd);
        return 0;
    }
    return 0;
}

_Bool is_already_executed(int _index, Node** root) {
    _Bool has_no_repeats = 1;
    for (Node* curr = root; curr != NULL; curr = curr->next) {
        if (curr->value == _index) {
            has_no_repeats = 0;
        }
    }
    return has_no_repeats;
}

void day8() {
    const size_t LENGTH = 625;
    char* lines[LENGTH];
    file_to_array("inputs/day8.txt", lines);
    printf("day8:\n");
    Node* exexuted_indexes = NULL;
    int index = 0;
    _Bool has_no_repeats = 1;
    while (index < LENGTH && has_no_repeats) {
        int index_adjustment = instruction_manager(lines[0], has_no_repeats);
        index += index_adjustment;
    }
}