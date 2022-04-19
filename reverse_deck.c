// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reverse_deck.h"
#include "list.h"
#include "function.h"

void reverse_deck(doubly_linked_list_t *deck_dll) {
    int index_list;
    scanf("%d", &index_list);

    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    if (index_list >= deck_dll->size || index_list < 0) {
        printf("The provided index is out of bounds for the deck list.\n");
        return;
    }

    dll_node_t *curr_node_list;
    curr_node_list =(dll_node_t*)dll_get_nth_node(deck_dll, index_list);
    doubly_linked_list_t *list = (doubly_linked_list_t*)curr_node_list->data;
    // create new deck
    doubly_linked_list_t *cards_dll = dll_create(sizeof(dll_node_t));

    dll_node_t *node = list->head->prev;
    int n = list->size;
    int i = 0;
    // as long as there are cards in the deck, move them
    while (n) {
        dll_add_nth_node(cards_dll, i, node->data);
        node = node->prev;
        i++;
        n--;
    }
    // add the new deck to the big deck
    dll_add_nth_node(deck_dll, index_list, cards_dll);
    free(cards_dll);
    // remove the old deck
    dll_node_t* trash = dll_remove_nth_node(deck_dll, index_list + 1);
    doubly_linked_list_t* trash_deck = (doubly_linked_list_t*)trash->data;

    dll_free(&trash_deck);
    free(trash);

    printf("The deck %d was successfully reversed.\n", index_list);
}
