#ifndef STACK_INT_HEADER
#define STACK_INT_HEADER

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* head;
    int size;
};

// Allocate memory for stack and initialise the head to NULL
// and the size to 0.
// Return pointer to stack
struct Stack* init_stack();

// Allocate memory for node, set node data to value and 
// pointer to next node to NULL
// Return pointer to node
struct Node* create_node(int value);

// Push value onto the stack
void push_stack(struct Stack* stack, int value);

// Pop the top value off the stack and return it
// Returns 0 if the stack is empty
// User is expected to check if the stack is empty
// Frees the memory of the popped node
int pop_stack(struct Stack* stack);

// Pops all values off the stack, emptying it
void clear_stack(struct Stack* stack);

// Empties the stack and frees the memory
void free_stack(struct Stack* stack);

// Prints the contents of the stack for testing and debugging
void print_stack(struct Stack* stack);

#endif
