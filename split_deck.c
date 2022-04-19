// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reverse_deck.h"
#include "list.h"
#include "function.h"

void split_deck(doubly_linked_list_t *deck_dll) {
    int index_list, index_split;

    scanf("%d%d", &index_list, &index_split);

    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    if (index_list >= deck_dll->size || index_list < 0) {
        printf("The provided index is out of bounds for the deck list.\n");
        return;
    }

    if (index_split == 0) {
        printf("The deck %d was successfully split by index %d.\n", index_list,
        index_split);
        return;
    }

    dll_node_t *curr_node_list;
    curr_node_list = (dll_node_t*)dll_get_nth_node(deck_dll, index_list);
    doubly_linked_list_t *list = (doubly_linked_list_t*)curr_node_list->data;

    if (index_split >= list->size || index_split < 0) {
        printf("The provided index is out of bounds for deck %d.\n",
        index_list);
        return;
    }
    // create new deck
    doubly_linked_list_t *cards_dll = dll_create(sizeof(dll_node_t));

    int n = list->size - index_split;
    int m = list->size;
    int i = 0;
    dll_node_t *node = (dll_node_t*)dll_get_nth_node(list, index_split);
    // move last size - index split cards to the new deck
    while (n) {
        dll_add_nth_node(cards_dll, i, node->data);
        node = node->next;
        i++;
        n--;
    }

    n = list->size - index_split;
    // remove last size - index split cards from the intial deck
    while (n) {
        dll_node_t *trash = dll_remove_nth_node(list, list->size);
        free(trash->data);
        free(trash);
        n--;
    }
    // add the new deck to the big deck
    dll_add_nth_node(deck_dll, index_list + 1, cards_dll);
    free(cards_dll);
    // if the initial deck size becomes 0, remove it
    if (index_split == m) {
        dll_node_t* trash = dll_remove_nth_node(deck_dll, index_list + 1);
        doubly_linked_list_t* trash_deck = (doubly_linked_list_t*)trash->data;

        dll_free(&trash_deck);
        free(trash);
    }

    printf("The deck %d was successfully split by index %d.\n", index_list,
    index_split);
}
