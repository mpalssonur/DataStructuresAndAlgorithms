#ifndef SINGLY_LINKED_LIST_INT_HEADER
#define SINGLY_LINKED_LIST_INT_HEADER

struct Node {
    int data;
    struct Node* next;
};

struct SinglyLinkedList {
    struct Node* head;
    int length;
};

struct SinglyLinkedList* create_list();

struct SinglyLinkedList* init_list();

struct Node* create_node(int value);

void list_add_start(struct SinglyLinkedList* list, int value);

void list_add_index(struct SinglyLinkedList* list, int index, int value);

void list_add_end(struct SinglyLinkedList* list, int value);

void list_delete_start(struct SinglyLinkedList* list);

void list_delete_value(struct SinglyLinkedList* list, int value);

void list_delete_index(struct SinglyLinkedList* list, int index);

void empty_list(struct SinglyLinkedList* list);

void free_list(struct SinglyLinkedList* list);

void print_list(struct SinglyLinkedList* list);

#endif
