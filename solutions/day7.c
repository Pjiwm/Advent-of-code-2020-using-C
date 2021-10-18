#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char* get_rule_bag(char* str) {
    char* return_string = (char*)malloc(32 * sizeof(char));
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
    return return_string;
}

char* get_bag_without_num(char* str) {
    char* return_string = (char*)malloc(32 * sizeof(char));
    int i = 2;
    while (i < strlen(str)) {
        return_string[i - 2] = str[i];
        i++;
    }
    return_string[i - 2] = '\0';
    return return_string;
}

_Bool is_gold_bag(char* str) {
    _Bool is_gold_bag = 1;
    char* str_no_num = get_bag_without_num(str);
    char cmp_str[11] = "shiny gold";
    for (int i = 0; i < strlen(str_no_num); i++) {
        if (str_no_num[i] != cmp_str[i]) is_gold_bag = 0;
    }
    return is_gold_bag;

}

void get_bags_from_rule(char* rule, Node** bags) {
    char* bag = (char*)malloc(32 * sizeof(char));
    size_t bag_index = 0;
    for (size_t i = 0; i < strlen(rule); i++) {
        if (is_bag_beginning(rule, i) || (rule[i - 2] == ',' && rule[i - 1] == ' ')) {
            while (!is_bag_end(rule, i + bag_index)) {
                bag[bag_index] = rule[i + bag_index];
                bag_index++;
            }
            bag[bag_index] = '\0';
            insert_tail(bags, strdup(bag));
            bag_index = 0;
        }
    }
}

_Bool find_gold_bags(char* bag, char* rules[], size_t LENGTH) {
    Node* bags = NULL;
    _Bool has_gold_bag = 0;


    for (size_t i = 0; i < LENGTH; i++) {
        // Loop over line, we start at 2 to skip the number at the beginning of the string/
        _Bool is_rule_from_bag = 1;
        for (size_t j = 0; j < strlen(bag); j++) {
            if (bag[j] != rules[i][j]) {
                is_rule_from_bag = 0;
            }
        }
        if (is_rule_from_bag) {
            get_bags_from_rule(rules[i], &bags);
            for (Node* curr = bags; curr != NULL; curr = curr->next) {
                if (is_gold_bag(curr->value)) {
                    return 1;
                }
                else {
                    has_gold_bag = find_gold_bags(get_bag_without_num(curr->value), rules, LENGTH);
                }
                if (has_gold_bag) {
                    return has_gold_bag;
                }
            }
            deallocate(&bags);
        }
    }
    return has_gold_bag;
}

size_t count_bags_in_gold_bag(char* bag, char* rules[], size_t LENGTH) {
    Node* bags = NULL;
    size_t bag_count = 0;


    for (size_t i = 0; i < LENGTH; i++) {
        // Loop over line, we start at 2 to skip the number at the beginning of the string/
        _Bool is_rule_from_bag = 1;
        for (size_t j = 0; j < strlen(bag); j++) {
            if (bag[j] != rules[i][j]) {
                is_rule_from_bag = 0;
            }
        }
        if (is_rule_from_bag) {
            get_bags_from_rule(rules[i], &bags);
            for (Node* curr = bags; curr != NULL; curr = curr->next) {
                size_t new_bag_count = atoi(&curr->value[0]);
                char* new_bag_name = get_bag_without_num(curr->value);
                bag_count += new_bag_count + (new_bag_count * count_bags_in_gold_bag(new_bag_name, rules, LENGTH));

            }
            deallocate(&bags);
        }
    }
    return bag_count;
}

void day7() {
    const size_t LENGTH = 594;
    char* rules[LENGTH];
    file_to_array("inputs/day7.txt", rules);

    printf("day7:\n");

    size_t bag_count = 0;
    for (size_t i = 0; i < LENGTH; i++) {
        char* bag = get_rule_bag(rules[i]);
        if (find_gold_bags(bag, rules, LENGTH)) bag_count++;
    }
    printf("%ld\n", bag_count);
    char* bag = get_rule_bag(rules[357]);
    printf("%ld\n", count_bags_in_gold_bag(bag, rules, LENGTH));

}



