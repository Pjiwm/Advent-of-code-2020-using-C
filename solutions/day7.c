#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <ctype.h>
// #include <stdbool.h>
#include "../helpers/file_reader.h"
// #include "../helpers/linked_list.h"
void day7() {
    const size_t LENGTH = 594;
    char* rules[LENGTH];
    file_to_array("inputs/day7.txt", rules);

    for (size_t i = 0; i < LENGTH; i++) {
        printf("%s\n", rules[i]);
    }
}


