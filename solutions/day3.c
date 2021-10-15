#include <stdio.h>
#include <stdlib.h>
#include "../helpers/file_reader.h"
#include <string.h>
long calculate_trees();
long product_of_trees();

void day3() {
    printf("day3:\n");
    printf("%ld\n", calculate_trees(3, 1));
    printf("%ld\n", product_of_trees());
}


long product_of_trees() {
    long total = 1;
    total *= calculate_trees(1, 1);
    total *= calculate_trees(3, 1);
    total *= calculate_trees(5, 1);
    total *= calculate_trees(7, 1);
    total *= calculate_trees(1, 2);
    return total;
}

long calculate_trees(int xStep, int yStep)
{
    const int MAP_ROWS = 323;
    char* map[MAP_ROWS];
    file_to_array("inputs/day3.txt", map);

    int x = 0;
    long treeCount = 0;
    for (int y = 0; y < MAP_ROWS; y += yStep)
    {

        if (map[y][x] == '#')
        {
            map[y][x] = 'X';
            treeCount++;
        }
        else
        {
            map[y][x] = 'O';
        }

        // printf("%s\n", map[y]);
        x += xStep;
        x %= 31;
    }
    return treeCount;
    free(map);
}
