#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../helpers/file_reader.h"
#include "../helpers/linked_list.h"
#include "../helpers/array_helper.h"

void day10() {
    const size_t LENGTH = 31;
    int jolts[LENGTH];
    printf("day 10:\n");
    file_to_int_array("inputs/test.txt", jolts);
    bubble_sort(jolts, LENGTH);

    int last_num = 0;
    size_t jolt3_count = 1;
    size_t jolt1_count = 0;
    for (size_t i = 0; i < LENGTH; i++) {
        if (jolts[i] - last_num == 1) {
            ++jolt1_count;
        }
        else {
            ++jolt3_count;
        }
        last_num = jolts[i];
    }
    printf("%ld\n", jolt1_count * jolt3_count);

    size_t possible_combinations = 0;
    _Bool has_combinations = 1;
    size_t remove_count = 1;
    while(has_combinations) {
        has_combinations = 0;
        for(size_t i = 0; i < LENGTH; i++) {
            
        }
    }

    // 19208
    printf("%ld\n", possible_combinations);
}