#ifndef LINKED_LIST
#define LINKED_LIST

//linked list node
struct Node{
        int data;
        struct Node *next;
};

struct Node* search_node(struct Node* head, int k);//working
struct Node* search_pos(struct Node* head, int pos);//working
void printList(struct Node* head);//working
void insert_at_beg(struct Node** head, int k);// working
void insert_at_pos(struct Node* head, int k, int pos);//indexing begins from zero =>working correctly
void insert_at_end(struct Node* head, int k);// working 
void delete_at_beg(struct Node** head);//working
void delete_at_pos(struct Node* head, int pos);//working
void delete_at_end(struct Node* head);//working
void print_reverse_list(struct Node* head);//working



#endif
