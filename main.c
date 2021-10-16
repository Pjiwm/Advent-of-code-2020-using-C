#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solutions/solutions.h"
#include "helpers/file_reader.h"
#include "helpers/linked_list.h"

int main()
{
    Node* root = NULL;
    insert_tail(&root, "s");
    insert_tail(&root, "sd");
    insert_tail(&root, "tit");
    insert_head(&root, "ddd");

    insert_after(root->next, "woo");

    for (Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%s\n", curr->value);
    }

    deallocate(&root);
    day1();
    day2();
    day3();
    day4();
    day5();
    day6();
    return 0;
}

