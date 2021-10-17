#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <ctype.h>
#include <stdbool.h>
#include "../helpers/file_reader.h"
#include "../helpers/linked_list.h"
_Bool is_bag_end(char* str, size_t index) {
    if (str[index] == ' ' && str[index + 1] == 'b' && str[index + 2] == 'a' && str[index + 3] == 'g') {
        return 1;
    }
    return 0;
}

_Bool is_bag_beginning(char* str, size_t index) {
    if (str[index - 1] == ' ' && str[index - 2] == 'n' && str[index - 3] == 'i' && str[index - 4] == 'a') {
        return 1;
    }
    return 0;
}

void bag_builder(char* str, size_t begin, size_t end, char* bag) {
    bag = (char*)malloc((end - begin) * sizeof(char));
    size_t index = begin;
    while (index < end) {
        bag[index] = str[index];
    }
}

size_t find_gold_bags(char* str, char* rules[], size_t LENGTH) {
    size_t count = (size_t)str[9];
    for (size_t i = 0; i < LENGTH; i++) {
        // Loop over line, we start at 2 to skip the number at the beginning of the string/
        _Bool is_same_bag = 1;
        for (size_t j = 2; j < strlen(str); j++) {
            if (str[j] != rules[i][j]) {
                is_same_bag = 0;
            }
        }
        if (is_same_bag) {

        }
    }
}

void get_bags_from_rule(char* rule, Node** bags) {
    char* bag = (char*)malloc(32 * sizeof(char));
    size_t bag_index = 0;
    for (size_t i = 0; i < strlen(rule); i++) {
        if (is_bag_beginning(rule, i) || (rule[i - 2] == ',' && rule[i - 1] == ' ')) {
            while (!is_bag_end(rule, i + bag_index)) {
                bag[bag_index] = rule[i + bag_index];
                printf("added letter: %c\n", rule[i + bag_index]);
                bag_index++;
            }
            bag[bag_index] = '\0';
            insert_tail(bags, strdup(bag));
            bag_index = 0;
            free(bag);
        }
    }
}


void day7() {
    const size_t LENGTH = 594;
    char* rules[LENGTH];
    file_to_array("inputs/day7.txt", rules);

    printf("day7:\n");
    printf("%s\n", rules[0]);
    // char* bags[] = malloc(500 * sizeof(char));
    Node* bags = NULL;
    get_bags_from_rule(rules[1], &bags);
    for (Node* curr = bags; curr != NULL; curr = curr->next) {
        // printf("%s l:%ld\n", curr->value, strlen(curr->value));
    }
}


