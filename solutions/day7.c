#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../helpers/file_reader.h"
#include "../helpers/linked_list.h"
// gold bag has to be fixed because a gold bag can be shiny gold bag, light gold bag etc.
_Bool is_gold_bag(char* str) {
    _Bool is_gold_bag = 0;
    if (str[2] == 'g' && str[3] == 'o' && str[4] == 'l' && str[5] == 'd') {
        is_gold_bag = 1;
    }
    return is_gold_bag;
}

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

char* get_rule_bag(char* str) {
    char* return_string;
    _Bool is_bag_name = 1;
    size_t i = 0;
    while (is_bag_name) {
        if (str[i + 1] == ' ' && str[i + 2] == 'b' && str[i + 3] == 'a' && str[i + 4] == 'g') {
            is_bag_name = 0;
        }
        return_string[i] = str[i];
        i++;
    }
    return_string[i] = '\0';
    printf("made bag: %s", return_string);
    return return_string;
}

char * get_bag_without_num(char* str) {
    char* return_string;
    int i = 2;
    while(i < strlen(str)) {
        return_string[i-2] = str[i];
        i++;
    }
    return_string[i-2] = '\0';
    printf("passing on bag: %s\n", return_string);
    return return_string;
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
            // free(bag);
        }
    }
}

size_t find_gold_bags(char* bag, char* rules[], size_t LENGTH) {
    Node* bags = NULL;
    size_t gold_bag_count = 0;

    for (size_t i = 0; i < LENGTH; i++) {
        // Loop over line, we start at 2 to skip the number at the beginning of the string/
        _Bool is_rule_from_bag = 1;
        printf("bag: %s\n", bag);
        for (size_t j = 0; j < strlen(bag); j++) {
            if (bag[j] != rules[i][j]) {
                is_rule_from_bag = 0;
            }
        }
        if (is_rule_from_bag) {
            get_bags_from_rule(rules[i], &bags);
            for (Node* curr = bags; curr != NULL; curr = curr->next) {
                size_t bag_count = (size_t)curr->value[0];
                if (is_gold_bag(curr->value)) gold_bag_count++;
                gold_bag_count += (bag_count * find_gold_bags(get_bag_without_num(curr->value), rules, LENGTH));
            }
            deallocate(&bags);
        }
    }

    return gold_bag_count;
}

void day7() {
    const size_t LENGTH = 9;
    char* rules[LENGTH];
    file_to_array("inputs/test.txt", rules);

    printf("day7:\n");
    printf("%s\n", rules[0]);
    // Node* bags = NULL;
    // get_bags_from_rule(rules[1], &bags);
    // for (Node* curr = bags; curr != NULL; curr = curr->next) {
    //     // printf("%s l:%ld\n", curr->value, strlen(curr->value));
    // }
    char* bag = get_rule_bag(rules[0]);
    printf("X\n");
    printf("%ld\n", find_gold_bags(bag, rules, LENGTH));

}


