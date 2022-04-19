// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exit.h"
#include "list.h"
#include "function.h"

void exit_function(doubly_linked_list_t *deck_dll)
{
    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    int n = deck_dll->size;

    for (int i = 0; i < n; i++) {
        // get cards
        dll_node_t *curr_node_list;
        curr_node_list = dll_get_nth_node(deck_dll, deck_dll->size - 1);

        doubly_linked_list_t *list;
        list = (doubly_linked_list_t*)curr_node_list->data;

        // free the little deck and its place in the big deck
        dll_free(&list);
        free(curr_node_list);
        list = NULL;
        // decrease list size
        deck_dll->size--;
    }

    // at the end, free the big deck
    dll_free(&deck_dll);
    deck_dll = NULL;
}
