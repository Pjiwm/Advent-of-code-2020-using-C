#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <ctype.h>
#include <stdbool.h>
#include "../helpers/file_reader.h"
// #include "../helpers/linked_list.h"
_Bool is_bag_end(char* str, size_t index) {
    if(str[index] == ' ' && str[index+1] == 'b' && str[index+2] == 'a' && str[index+3] == 'g') {
        return 1;
    }
    // char bag[4] = " bag";
    // for (size_t i = 0; i < 4; i++) {
    //     if (!str[index + i + 1] == bag[i]) {
    //         return 1;
    //     }
    // }
    return 0;
}

_Bool is_bag_beginning(char* str, size_t index) {
    if (str[index - 1] == ' ' && str[index - 2] == 'n' && str[index - 3] == 'i' && str[index - 4] == 'a') {
        printf("bag begins at index: %ld\n", index);
        printf("bag begins at char: %c\n", str[index]);
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

}

void rule_loop(char* rule) {
    char* bag = (char*)malloc(32 * sizeof(char));
    size_t bag_index = 0;
    for (size_t i = 0; i < strlen(rule); i++) {
        if (is_bag_beginning(rule, i) || (rule[i-2] == ',' && rule[i-1] == ' ')/*&& !is_bag_end(rule, i)*/) {
            while (!is_bag_end(rule, i + bag_index)) {
                printf("building bag\n");
                bag[bag_index] = rule[i + bag_index];
                bag_index++;
            }
            bag_index = 0;
            printf("made bag: %s with l: %ld \n", bag, strlen(bag));
            // bag = "\0";
        }
    }

    // printf("%s", bag);
}


void day7() {
    const size_t LENGTH = 594;
    char* rules[LENGTH];
    file_to_array("inputs/day7.txt", rules);

    // for (size_t i = 0; i < LENGTH; i++) {
    //     printf("%s\n", rules[i]);
    // }
    printf("day7:\n");
    // rule_loop("bags contain 5 dark brown Bags");
    printf("%s\n", rules[0]);
    rule_loop(rules[0]);
}


