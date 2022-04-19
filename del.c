// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "del.h"
#include "list.h"
#include "function.h"

void del_deck(doubly_linked_list_t *deck_dll) {
    int index;
    scanf("%d", &index);

    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    if (index >= deck_dll->size || index < 0) {
        printf("The provided index is out of bounds for the deck list.\n");
        return;
    }

    // use a trash variable for the deleted node
    dll_node_t* trash = dll_remove_nth_node(deck_dll, index);
    doubly_linked_list_t* trash_deck = (doubly_linked_list_t*)trash->data;

    // free trash and trash data
    dll_free(&trash_deck);
    free(trash);

    printf("The deck %d was successfully deleted.\n", index);
}


void del_card(doubly_linked_list_t *deck_dll)
{
    int index_list;
    int index_card;

    scanf("%d", &index_list);
    scanf("%d", &index_card);

    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    if (index_list >= deck_dll->size || index_list < 0) {
        printf("The provided index is out of bounds for the deck list.\n");
        return;
    }

    doubly_linked_list_t *list = (doubly_linked_list_t*)
    ((dll_get_nth_node(deck_dll, index_list))->data);

    if (index_card >= list->size || index_card < 0) {
        printf("The provided index is out of bounds for deck %d.\n",
        index_list);
        return;
    }
    // delete the indicated card and its data
    dll_node_t* trash = dll_remove_nth_node(list, index_card);
    free(trash->data);
    free(trash);

    // if there aren't any cards left, delete the deck
    if (list->size == 0) {
        dll_node_t* trash = dll_remove_nth_node(deck_dll, index_list);
        free(trash->data);
        free(trash);
    }

    printf("The card was successfully deleted from deck %d.\n", index_list);
}
