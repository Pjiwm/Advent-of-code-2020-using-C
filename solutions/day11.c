#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../helpers/file_reader.h"
#include "../helpers/array_helper.h"

bool can_occupy(int y, int x, char* seats[], const int LENGTH) {
    int adj_y;
    int adj_x;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            adj_y = y - j;
            adj_x = x - j; 
            printf("y:%d x:%d\n", adj_y, adj_x);
            if (adj_x >= 0 && adj_y >= 0 && adj_x < LENGTH && adj_y < LENGTH) {
                if (seats[y - i][x - j] == '#') {
                    return false;
                }
            }
        }
    }
    return true;
}

void day11() {
    const size_t LENGTH = 10;
    // seat map ratio is 1:1
    char* seats[LENGTH];
    char* temp_seats[LENGTH];
    printf("day 11:\n");
    file_to_array("inputs/test.txt", seats);
    copy_str_array(seats, temp_seats, LENGTH);
    can_occupy(0, 0, seats, LENGTH);
    for (size_t y = 0; y < LENGTH; y++) {
        for (size_t x = 0; x < LENGTH; x++) {

        }
    }


}