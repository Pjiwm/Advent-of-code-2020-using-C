#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../helpers/file_reader.h"

void day11() {
    const size_t LENGTH = 10;
    char * rows[LENGTH];
    printf("day 11:\n");
    file_to_array("inputs/test.txt", rows);
   
}