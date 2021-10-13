#include <stdio.h>
#include <stdlib.h>
#include "../helpers/file_reader.h"
#include <string.h>

void convert_arr_to_int(char* str_arr[], int* int_arr, size_t LENGTH) {

    for (size_t i = 0; i < LENGTH; i++) {
        int_arr[i] = atoi(str_arr[i]);
        free(str_arr[i]);
    }
}

int sum_2020_part1() {
    const size_t LENGTH = 200;
    char* numbers_strings[LENGTH];
    fileToArray("inputs/day1.txt", numbers_strings);
    int numbers[LENGTH];
    convert_arr_to_int(numbers_strings, numbers, LENGTH);

    // find match that makes 2020
    for (size_t i = 0; i < LENGTH; i++) {
        for (size_t j = 0; j < LENGTH; j++) {
            if (numbers[j] + numbers[i] == 2020) {
                return numbers[j] * numbers[i];
            }
        }
    }
    return 0;
}

long sum_2020_part2() {
    const size_t LENGTH = 200;
    char* numbers_strings[LENGTH];
    fileToArray("inputs/day1.txt", numbers_strings);
    int numbers[LENGTH];
    convert_arr_to_int(numbers_strings, numbers, LENGTH);

    // find match that makes 2020
    for (size_t i = 0; i < LENGTH; i++) {
        for (size_t j = 0; j < LENGTH; j++) {
            for (size_t k = 0; k < LENGTH; k++) {
                if (numbers[i] + numbers[j] + numbers[k] == 2020) {
                    return numbers[j] * numbers[i] * numbers[k];
                }
            }
        }
    }

    return 0;
}

void day1() {
    printf("day1:\n");
    printf("%d\n", sum_2020_part1());
    printf("%ld\n", sum_2020_part2());

}