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

// Allocate memory for queue, 
// initialise tail and head to NULL and 
// set length to 0
// Returns pointer to queue
struct Queue* init_queue();

// Allocate memory for node in queue
// with data=value. 
// Initialize next and prev to NULL
// Return pointer to node
struct Node* create_node(int value);

// Enqueue value at head of queue
void enqueue(struct Queue* queue, int value);

// Dequeue from the tail of the queue
// Return data of dequeued node
// Returns 0 if queue is empty
// User is expected to check if queue is empty
int dequeue(struct Queue* queue);

// Removes all nodes from queue
void clear_queue(struct Queue* queue);

// clears the queue and frees the memory
void free_queue(struct Queue* queue);

// prints the contents of the queue
// for testing and debugging
void print_queue(struct Queue* queue);

#endif











