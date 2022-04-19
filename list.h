// Copyright 2021 - 2022 Preda Diana 314CA

#ifndef LIST_H_
#define LIST_H_

#define BMAX 10

// node
typedef struct dll_node_t
{
    void* data;
    struct dll_node_t *prev, *next;
} dll_node_t;

// list
typedef struct doubly_linked_list_t
{
    dll_node_t* head;
    int data_size;
    int size;
} doubly_linked_list_t;

// caracteristics
typedef struct {
    int value;
    char symbol[BMAX];
} type;

doubly_linked_list_t*
dll_create(int data_size);

int dll_get_size(doubly_linked_list_t* list);

void
dll_add_nth_node(doubly_linked_list_t* list,  int n, const void* data);

dll_node_t*
dll_get_nth_node(doubly_linked_list_t* list,  int n);

dll_node_t*
dll_remove_nth_node(doubly_linked_list_t* list,  int n);

void
dll_free(doubly_linked_list_t** pp_list);

#endif  // LIST_H_
