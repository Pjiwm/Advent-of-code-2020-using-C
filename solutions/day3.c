#include <stdio.h>
#include <stdlib.h>
#include "../helpers/file_reader.h"
#include <string.h>
long calculateTrees();
long productOfTrees();

void day3() {
    printf("%ld\n", productOfTrees());
}


long productOfTrees() {
    long total = 1;
    total *= calculateTrees(1, 1);
    total *= calculateTrees(3, 1);
    total *= calculateTrees(5, 1);
    total *= calculateTrees(7, 1);
    total *= calculateTrees(1, 2);
    return total;
}

long calculateTrees(int xStep, int yStep)
{
    const int MAP_ROWS = 323;
    char *map[MAP_ROWS];
    fileToArray("inputs/day3.txt", map);

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
}
