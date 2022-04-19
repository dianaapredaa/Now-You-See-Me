// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "del.h"
#include "list.h"
#include "function.h"
#include "count.h"

void deck_number(doubly_linked_list_t *deck_dll)
{
    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    printf("The number of decks is %d.\n", deck_dll->size);
}

void deck_len(doubly_linked_list_t *deck_dll) {
    int deck_number;
    scanf("%d", &deck_number);

    // check for invald commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    if (deck_number >= deck_dll->size || deck_number < 0) {
        printf("The provided index is out of bounds for the deck list.\n");
        return;
    }

    dll_node_t *curr_node_list = dll_get_nth_node(deck_dll, deck_number);
    doubly_linked_list_t *list = (doubly_linked_list_t*)curr_node_list->data;

    printf("The length of deck %d is %d.\n", deck_number, list->size);
}
