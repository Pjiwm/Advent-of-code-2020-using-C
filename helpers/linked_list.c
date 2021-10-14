#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void insert_tail(Node** _root, int _value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->next = NULL;
    newNode->value = _value;

    if (*_root == NULL) {
        *_root = newNode;
        return;
    }

    Node* curr = *_root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void insert_head(Node** _root, int _value) {
    Node* new_node = malloc(sizeof(Node));
    // if(new_node == NULL) {
    //     return 3;
    // }
    new_node->value = _value;
    new_node->next = *_root;

    *_root = new_node;
}

void deallocate(Node** _root) {
    Node* curr = *_root;

    while (curr != NULL) {
        Node* aux = curr;
        curr = curr->next;
        free(aux);
    }

    *_root = NULL;
}

int main() {
    Node* root = NULL;
    insert_head(&root, 10);
    insert_head(&root, 11);
    insert_tail(&root, 2);

    for(Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d\n", curr->value);
    }

    deallocate(&root);
    return 0;
}