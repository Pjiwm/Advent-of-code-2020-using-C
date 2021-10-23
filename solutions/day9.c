#include <stdio.h>
#include <stdlib.h>
#include "../helpers/file_reader.h"
#include "../helpers/linked_list.h"

void day9() {
    const size_t LENGTH = 1000;
    long long int numbers[LENGTH];
    printf("b\n");
    file_to_long_long_int_array("inputs/day9.txt", numbers);
    for (size_t i = 0; i < LENGTH; i++) {
        printf("%lld\n", numbers[i]);
    }
}