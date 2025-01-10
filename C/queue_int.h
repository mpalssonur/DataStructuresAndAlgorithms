#ifndef QUEUE_INT_HEADER
#define QUEUE_INT_HEADER

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
    int length;
};

struct Queue* init_queue();

struct Node* create_node(int value);

void enqueue(struct Queue* queue, int value);

int dequeue(struct Queue* queue);

void clear_queue(struct Queue* queue);

void free_queue(struct Queue* queue);

void print_queue(struct Queue* queue);

#endif











