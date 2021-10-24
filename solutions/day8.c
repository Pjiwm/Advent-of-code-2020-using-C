#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../helpers/file_reader.h"
#include "../helpers/linked_list.h"

int accumulator = 0;
Int_Node* executed_indexes = NULL;

int instruction_manager(char* _instruction) {

    char* instruction = strdup(_instruction);
    char* cmd = strtok(strdup(instruction), " ");
    int amount = atoi(strtok(NULL, " "));
    if (strcmp(cmd, "jmp") == 0) {
        return amount;
    }
    else if (strcmp(cmd, "acc") == 0) {
        accumulator += amount;
        return 1;
    }
    else if (strcmp(cmd, "nop") == 0) {
        return 1;
    }
    else {
        printf("Unknown command: %s\n", cmd);
        return 0;
    }
    return 0;
}

_Bool is_already_executed(int _index, Int_Node* root) {
    for (Int_Node* curr = root; curr != NULL; curr = curr->next) {
        if (curr->value == _index) {
            return 0;
        }
    }
    return 1;
}

void day8() {
    const size_t LENGTH = 625;
    char* instructions[LENGTH];
    file_to_array("inputs/day8.txt", instructions);
    printf("day 8:\n");
    // part 1
    int index = 0;
    _Bool has_no_repeats = 1;
    while (index < LENGTH && has_no_repeats) {
        int_insert_tail(&executed_indexes, index);
        int index_adjustment = instruction_manager(instructions[index]);
        index += index_adjustment;
        has_no_repeats = is_already_executed(index, executed_indexes);
    }
    printf("%d\n", accumulator);
    int_deallocate(&executed_indexes);
    accumulator = 0;

    // part 2
    for (size_t i = 0; i < LENGTH; i++) {
        int index = 0;
        _Bool has_no_repeats = 1;
        while (index < LENGTH && has_no_repeats) {
            int_insert_tail(&executed_indexes, index);
            if (index == i) {
                index++;
            }
            int index_adjustment = instruction_manager(instructions[index]);
            index += index_adjustment;
            has_no_repeats = is_already_executed(index, executed_indexes);
        }
        if (has_no_repeats) {
            i = LENGTH;
        }
        else {
            has_no_repeats = 1;
            int_deallocate(&executed_indexes);
            accumulator = 0;
        }
    }
    int_deallocate(&executed_indexes);
    printf("%d\n", accumulator);
}