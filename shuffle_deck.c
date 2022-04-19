// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shuffle_deck.h"
#include "list.h"
#include "function.h"

void shuffle_deck(doubly_linked_list_t *deck_dll) {
    int index_list;
    scanf("%d", &index_list);

    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    if (index_list >= deck_dll->size) {
        printf("The provided index is out of bounds for the deck list.\n");
        return;
    }

    if (index_list < 0) {
        printf("The provided index is out of bounds for the deck list.\n");
        return;
    }

    dll_node_t *curr_node_list;
    curr_node_list = (dll_node_t*)dll_get_nth_node(deck_dll, index_list);
    doubly_linked_list_t *list = (doubly_linked_list_t*)curr_node_list->data;

    // go to the middle and switch
    list->head = dll_get_nth_node(list, list->size / 2);

    printf("The deck %d was successfully shuffled.\n", index_list);
}
