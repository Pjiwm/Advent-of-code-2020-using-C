#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char* value;
    struct Node* next;
} Node;
// add element to end of list
void insert_tail(Node** _root, char* _value) {
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
// add element to beginning of list
void insert_head(Node** _root, char* _value) {
    Node* new_node = malloc(sizeof(Node));
    // if(new_node == NULL) {
    //     return 3;
    // }
    new_node->value = _value;
    new_node->next = *_root;

    *_root = new_node;
}
// add element after root
void insert_after(Node* node, char* value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = node->next;
    node->next = new_node;
    // if(new_node == NULL) {
    //     return 4;
    // }
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
    insert_tail(&root, "s");
    insert_tail(&root, "sd");
    insert_tail(&root, "tit");
    insert_head(&root, "ddd");

    insert_after(root->next, "woo");

    for (Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%s\n", curr->value);
    }

    deallocate(&root);
    return 0;
}