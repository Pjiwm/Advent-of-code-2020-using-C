#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../helpers/file_reader.h"
#include "../helpers/linked_list.h"

long long int smallest(long long int nums[], size_t LENGTH) {
    long long int smallest = nums[0];
    for (size_t i = 0; i < LENGTH; i++) {
        if (nums[i] < smallest) {
            smallest = nums[i];
        }
    }
    return smallest;
}

long long int largest(long long int nums[], size_t LENGTH) {
    long long int largest = nums[0];
    for (size_t i = 0; i < LENGTH; i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }
    return largest;
}

void day9() {
    const size_t INPUT_LENGTH = 1000;
    const size_t PREAMBLE_LENGTH = 25;
    const size_t NUMBER_LENGTH = 975;
    long long int input[INPUT_LENGTH];
    long long int preamble[PREAMBLE_LENGTH];
    long long int numbers[NUMBER_LENGTH];
    long long int weakness_number;
    Long_Long_Int_Node* valid_numbers = NULL;
    file_to_long_long_int_array("inputs/day9.txt", input);
    printf("day 9:\n");

    for (size_t i = 0; i < NUMBER_LENGTH; i++) {
        numbers[i] = input[i + 25];
    }
    // part 1 
    for (size_t i = 0; i < NUMBER_LENGTH; i++) {
        for (size_t j = 0; j < PREAMBLE_LENGTH; j++) {
            preamble[j] = input[j + i];
        }
        for (size_t j = 0; j < PREAMBLE_LENGTH; j++) {
            for (size_t k = 0; k < PREAMBLE_LENGTH; k++) {
                if (preamble[j] != preamble[k]) {
                    long_long_int_insert_tail(&valid_numbers, preamble[j] + preamble[k]);
                }
            }
        }

        _Bool found_value = 0;
        for (Long_Long_Int_Node* curr = valid_numbers; curr != NULL; curr = curr->next) {
            if (numbers[i] == curr->value) {
                found_value = 1;
            }
        }
        if (!found_value) {
            printf("%lld\n", numbers[i]);
            weakness_number = numbers[i];
            i = NUMBER_LENGTH;
        }
        long_long_int_deallocate(&valid_numbers);
    }

    // part 2
    size_t min_idx;
    size_t max_idx;
    for (size_t i = 0; i < INPUT_LENGTH; i++) {
        long long int sum = 0;
        for (size_t j = i; j < INPUT_LENGTH; j++) {
            sum += input[j];
            if (sum == weakness_number) {
                min_idx = i;
                max_idx = j;
                j = INPUT_LENGTH;
                i = INPUT_LENGTH;
            }
        }
    }
    long long int weakness_range[max_idx + 1];
    for (size_t i = 0; i < max_idx + 1; i++) {
        weakness_range[i] = input[min_idx + i];
    }
    printf("%lld\n", smallest(weakness_range, PREAMBLE_LENGTH) + largest(weakness_range, PREAMBLE_LENGTH));

}