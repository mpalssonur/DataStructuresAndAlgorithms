#include <stdio.h>
#include <stdlib.h>
#include "stack_int.h"

struct Stack* init_stack() {
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

struct Node* create_node(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void push_stack(struct Stack* stack, int value) {
    struct Node* new_node = create_node(value);
    new_node->next = stack->head;
    stack->head = new_node;
    stack->size++;
    return;
}

int pop_stack(struct Stack* stack) {
    if (stack->head == NULL) {
        return 0;
    }
    struct Node* tmp = stack->head;
    int value = tmp->data;
    stack->head = tmp->next;
    tmp->next = NULL;
    tmp->data = 0;
    free(tmp);
    stack->size--;
    return value;
}

void clear_stack(struct Stack* stack) {
    int i;
    while(stack->head) {
        i = pop_stack(stack);
    }
    return;
}

void free_stack(struct Stack* stack) {
    clear_stack(stack);
    free(stack);
}

void print_stack(struct Stack* stack) {
    struct Node* current = stack->head;
    while(current) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

int main() {

    struct Stack* stack = init_stack();
    
    for(int i = 0; i < 20; i++) {
        push_stack(stack, i);
    }
    print_stack(stack);
    for(int i = 0; i < 10; i++) {
        printf("%d\n", pop_stack(stack));
    }
    print_stack(stack);
    free_stack(stack);

    return 0;
}












