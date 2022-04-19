// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "utils.h"

#define MAX_STRING_SIZE 64

// create new list
doubly_linked_list_t*
dll_create(int data_size)
{
    doubly_linked_list_t *list;
    list = malloc(sizeof(*list));
    DIE(NULL == list, "malloc failed");

    list->head = NULL;
    list->data_size = data_size;
    list->size = 0;

    return list;
}

// find the actual size
int
dll_get_size(doubly_linked_list_t* list)
{
    return list->size;
}

// get whatever node you want
dll_node_t*
dll_get_nth_node(doubly_linked_list_t* list,  int n)
{
    dll_node_t *node;

    if (!list || !list->size)
        return NULL;

    node = list->head;
    n = n % list->size;

    for ( int i = 0; i < n; i++)
        node = node->next;

    return node;
}

// add another node
void
dll_add_nth_node(doubly_linked_list_t* list,  int n, const void* data)
{
    dll_node_t* new_node = malloc(sizeof(dll_node_t));
	DIE(NULL == new_node, "malloc failed");

    if (n > list->size)
        n = list->size;

    new_node->data = malloc(list->data_size);
    DIE(NULL == new_node->data, "malloc failed");
    memcpy(new_node->data, data, list->data_size);

    // if there is no node
    if (list->size == 0) {
        list->head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;

    // if it's first
    } else if (list->size > 0 && n == 0) {
        new_node->next = list->head;
        new_node->prev = list->head->prev;
        list->head->prev->next = new_node;
        list->head->prev = new_node;
        list->head = new_node;

    // if it's last
    } else if (list->size > 0 && n == list->size) {
        dll_node_t *node = dll_get_nth_node(list, list->size - 1);
        new_node->next = list->head;
        new_node->prev = node;
        list->head->prev->next = new_node;
        list->head->prev = new_node;

    // anything else
    } else {
        dll_node_t *node = dll_get_nth_node(list, n - 1);
        new_node->next = node->next;
        new_node->prev = node;
        node->next->prev = new_node;
        node->next = new_node;
    }
    // increase size
    list->size++;
}

// remove a node
dll_node_t*
dll_remove_nth_node(doubly_linked_list_t* list,  int n)
{
    dll_node_t *node;
    if (n > list->size - 1)
        n = list->size - 1;

    if (list == NULL || list->size == 0)
        return NULL;

    // if there is only one node
    if (list->size == 1) {
        node = list->head;
        list->head = NULL;

    // if it's the last node
    } else if (n == (list->size - 1)) {
        node = list->head->prev;
        list->head->prev->prev->next = list->head;
        list->head->prev = node->prev;

    // if it's the first node
    } else if (n == 0 && list->size > 1) {
        node = list->head;

        list->head->next->prev = node->prev;
        list->head->prev->next = node->next;

        list->head = node->next;

    // anything else
    } else {
        dll_node_t* another_node = dll_get_nth_node(list, n - 1);
        node = another_node->next;
        another_node->next->next->prev = another_node;
        another_node->next = node->next;
    }

    node->next = NULL;
    node->prev = NULL;

    // decrease size
    list->size--;
    return node;
}

// get rid of them
void
dll_free(doubly_linked_list_t** pp_list)
{
    doubly_linked_list_t* list = *pp_list;
    dll_node_t* node = list->head;
    dll_node_t *another_node;

    // free nodes and data
    for (int i = 0; i < list->size; i++) {
        another_node = node->next;
        free(node->data);
        free(node);
        node = another_node;
    }
    // lastly, free the list
    free(list);
}
