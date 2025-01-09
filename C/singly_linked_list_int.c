#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
struct Node {
    int data;
    struct Node* next;
};

struct SinglyLinkedList {
    struct Node* head;
    int length;
};

struct SinglyLinkedList* create_list() {
    struct SinglyLinkedList *list = malloc(sizeof(struct SinglyLinkedList));
    return list;
}

struct SinglyLinkedList* init_list() {
    struct SinglyLinkedList *list = create_list();
    if (list == NULL) {
        printf("Creation of list failed");
        return 0;
    }
    list->head = NULL;
    list->length = 0;
    return list;
}

void list_add_start(struct SinglyLinkedList* list, int value) {
    struct Node* new_node = malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Allocation of Node failed. Adding %d to list failed", value);
        return;
    }
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    list->length++;
}

void list_add_index(struct SinglyLinkedList* list, int index, int value) {
    if (index <= 0) {
        list_add_start(list, value);
        return;
    }

    struct Node* new_node = malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Allocation of Node failed. Adding %d to list at index %d failed", value, index);
        return;
    }

    struct Node* current_node = list->head;
    int i = 0;
    while ((i < index) && (current_node->next)) {
        i++;
        current_node = current_node->next;
    }

    new_node->data = value;
    new_node->next = current_node->next;
    current_node->next = new_node;
    list->length++;
    return;
}

void list_delete_start(struct SinglyLinkedList* list) {
    if (list->head == NULL) return;

    struct Node* tmp = list->head;
    list->head = list->head->next;
    tmp->next = NULL;
    tmp->data = 0;
    free(tmp);
    list->length--;
    return;
}

void list_delete_value(struct SinglyLinkedList* list, int value) {
    if (list->head == NULL) {
        return;
    }
    struct Node* current_node = list->head;
    if (current_node->data == value) {
        list->head = current_node->next;
        list->length--;
        current_node->next = NULL;
        current_node->data = 0;
        free(current_node);
        return;
    }
    struct Node* next_node = current_node->next;
    while(next_node) {
        if (next_node->data == value) {
            current_node->next = next_node->next;
            next_node->next = NULL;
            next_node->data = 0;
            free(next_node);
            list->length--;
            return;
        }
        else {
            current_node = next_node;
            next_node = next_node->next;
        }
    }
    return;
}

void print_list(struct SinglyLinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

int main() {
    struct SinglyLinkedList* list = init_list();

    for(int i = 0; i < 10; i++) {
        list_add_start(list, i);
    }
    list_add_index(list, 5, 50);

    print_list(list);

    return 0;
}
