// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "show_deck.h"
#include "list.h"
#include "function.h"

void show(doubly_linked_list_t *deck_dll,  int deck_number)
{
    dll_node_t *curr_node_list = dll_get_nth_node(deck_dll, deck_number);
    doubly_linked_list_t *list = (doubly_linked_list_t*)curr_node_list->data;
    dll_node_t * curr_node = (dll_node_t*)list->head;

    printf("Deck %d:\n", deck_number);

    // iterate through the little deck and show its data
    for (int i = 0; i < list->size; i++) {
        printf("\t%d ", ((type*)curr_node->data)->value);
        printf("%s\n", ((type*)curr_node->data)->symbol);
        curr_node = curr_node->next;
    }
}

void show_deck(doubly_linked_list_t *deck_dll)
{
    int deck_number;
    scanf("%d", &deck_number);

    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    if (deck_number >= deck_dll->size || deck_number < 0) {
        printf("The provided index is out of bounds for the deck list.\n");
        return;
    }
    // use show function to display the indicated deck
    show(deck_dll, deck_number);
}

void show_all(doubly_linked_list_t *deck_dll)
{
    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    // use show function to display one by one all the decks
    for (int i = 0; i < deck_dll->size; i++) {
        show(deck_dll, i);
    }
}
