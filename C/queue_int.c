#include <stdio.h>
#include <stdlib.h>
#include "queue_int.h"

struct Queue* init_queue() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->length = 0;
    return queue;
}

struct Node* create_node(int value) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void enqueue(struct Queue* queue, int value) {
    struct Node* new_node = create_node(value);

    if (queue->length == 0) {
        queue->head = queue->tail = new_node;
        queue->length++;
        return;
    }

    new_node->next = queue->head;
    queue->head->prev = new_node;
    queue->head = new_node;
    queue->length++;
    return;
}

int dequeue(struct Queue* queue) {
    if(queue->length == 0) {
        return 0;
    }
    struct Node* tmp = queue->tail;
    int value = tmp->data;
    tmp->data = 0;
    if(queue->length == 1) {
        queue->head = queue->tail = NULL;
        free(tmp);
    }
    else {
        queue->tail = tmp->prev;
        queue->tail->next = NULL;
        tmp->prev = NULL;
        free(tmp);
    }
    queue->length--;
    return value;
}

void clear_queue(struct Queue* queue) {
    int i;
    while(queue->length) {
        i = dequeue(queue);
    }
    return;
}

void free_queue(struct Queue* queue) {
    clear_queue(queue);
    free(queue);
}

void print_queue(struct Queue* queue) {
    struct Node* current = queue->head;
    while(current) {
        printf("%d->",current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

int main() {

    struct Queue* queue = init_queue();

    for(int i = 0; i <= 20; i++) {
        enqueue(queue, i);
    }
    print_queue(queue);

    for(int i = 0; i < 10; i++) {
        printf("%d\n", dequeue(queue));
    }
    print_queue(queue);

    free_queue(queue);
    
    return 0;
}












