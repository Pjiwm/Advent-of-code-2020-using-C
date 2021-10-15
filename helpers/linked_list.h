#pragma once
// have to look up how to get struct here?
 typedef struct Node {
    char* value;
    struct Node* next;
} Node;
void insert_tail(Node** _root, char* _value);
void insert_head(Node** _root, char* _value);
void insert_after(Node* node, char* value);
void deallocate(Node** _root);