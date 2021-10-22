#pragma once
#define TABLE_SIZE 20000
// have to look up how to get struct here?
 typedef struct String_Node {
    char * value;
    struct String_Node* next;
} String_Node;
void str_insert_tail(String_Node** _root, char* _value);
void str_insert_head(String_Node** _root, char* _value);
void str_insert_after(String_Node* node, char* value);
void str_deallocate(String_Node** _root);
 typedef struct Int_Node {
    int value;
    struct Int_Node* next;
} Int_Node;
void int_insert_tail(Int_Node** _root, int _value);
void int_insert_head(Int_Node** _root, int _value);
void int_insert_after(Int_Node* node, int value);
void int_deallocate(Int_Node** _root);
