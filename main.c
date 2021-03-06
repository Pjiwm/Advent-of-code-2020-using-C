#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "solutions/solutions.h"
#include "helpers/file_reader.h"
void run_all() {
    day1();
    day2();
    day3();
    day4();
    day5();
    day6();
    day7();
    day8();
    day9();
    day10();
    day11();
}


int main(int argc, char** argv) {
    int8_t day = 0;
    if (argc > 1) {
        day = atoi(argv[1]);
    }
    switch (day) {
    case 1:
        day1();
        break;
    case 2:
        day2();
        break;
    case 3:
        day3();
        break;
    case 4:
        day4();
        break;
    case 5:
        day5();
        break;
    case 6:
        day6();
        break;
    case 7:
        day7();
        break;
    case 8:
        day8();
        break;
    case 9:
        day9();
        break;
    case 10:
        day10();
        break;
    case 11:
        day11();
        break;
    default:
        printf("No specific or invalid argument.\n displaying all days.\n");
        run_all();
        break;
    }

    return 0;
}

