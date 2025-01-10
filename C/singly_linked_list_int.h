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

// Allocates memory for list and returns pointer
struct SinglyLinkedList* create_list();

// calls create_list() and sets head to NULL and length to 0.
// returns pointer to the list
struct SinglyLinkedList* init_list();

// Allocates memory for a list node,
// sets the pointer to next node to NULL and 
// node data to the input value
// Returns pointer to the new node.
struct Node* create_node(int value);

// Adds node at the start of the list with data=value
void list_add_start(struct SinglyLinkedList* list, int value);

// Adds node at given index in the list with data=value
// If the list is not long enough to reach the index,
// the node is added at the end.
void list_add_index(struct SinglyLinkedList* list, int index, int value);

// Adds node at the end of the list with data=value
void list_add_end(struct SinglyLinkedList* list, int value);

// Removes the front node of the list
void list_delete_start(struct SinglyLinkedList* list);

// Deletes the first node in the list with data=value
// Does nothing if no node contains value
void list_delete_value(struct SinglyLinkedList* list, int value);

// Deletes the node at the given index
// Does nothing if list is too short to contain the index
void list_delete_index(struct SinglyLinkedList* list, int index);

// Deletes every node of the list
void empty_list(struct SinglyLinkedList* list);

// Frees the memory allocated to the list
void free_list(struct SinglyLinkedList* list);

// Prints the contents of the list for testing and debugging.
void print_list(struct SinglyLinkedList* list);

#endif
