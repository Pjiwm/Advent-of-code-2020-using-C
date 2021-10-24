#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helpers/file_reader.h"
#include "../helpers/array_helper.h"

// void bubble_sort(size_t* arr, size_t LENGTH) {
//     _Bool is_sorted = 0;
//     while (!is_sorted) {
//         is_sorted = 1;
//         for (size_t i = 0; i < LENGTH; i++) {
//             if (arr[i] > arr[i + 1]) {
//                 size_t temp = arr[i + 1];
//                 arr[i + 1] = arr[i];
//                 arr[i] = temp;
//                 is_sorted = 0;
//             }
//         }
//     }
// }

size_t calculate_id(size_t row, size_t column) {
    return row * 8 + column;
}

void set_row_and_column(size_t* row, size_t* column, char* line) {
    size_t min = 0;
    size_t max = 127;

    // find row
    for (int i = 0; i < 6; i++) {
        if (line[i] == 'F') {
            max = (min + max) / 2;
        }
        else {
            min += (max - min) / 2 + 1;
        }
    }
    if (line[6] == 'F') {
        *row = min;
    }
    else {
        *row = max;
    }

    min = 0;
    max = 7;
    // find column
    for (int i = 7; i < 9; i++) {
        if (line[i] == 'L') {
            max = (min + max) / 2;
        }
        else {
            min += (max - min) / 2 + 1;
        }
    }

    if (line[9] == 'L') {
        *column = min;
    }
    else {
        *column = max;
    }
}

void day5() {
    const size_t LENGTH = 824;
    char* lines[LENGTH];
    size_t IDs[LENGTH];
    size_t highest = 0;
    file_to_array("inputs/day5.txt", lines);
    for (int i = 0; i < LENGTH; i++) {
        size_t row, column;
        set_row_and_column(&row, &column, lines[i]);
        size_t new_id = calculate_id(row, column);
        IDs[i] = new_id;
        if (new_id > highest) {
            highest = new_id;
        }
        // printf("%ld\n", new_id);
    }
    size_t_bubble_sort(IDs, LENGTH);
    printf("day5:\n");
    printf("%ld\n", highest);
    for (size_t i = 0; i < LENGTH; i++) {
        if (IDs[i] != i + 54) {
            printf("%ld\n", IDs[i]);
            i = LENGTH;
        }
    }
    free(*lines);

}