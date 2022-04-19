// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "add.h"
#include "list.h"
#include "function.h"

#define BMAX 10

// add_deck function
void add_deck(doubly_linked_list_t *deck_dll) {
    int cards_number;
    scanf("%d", &cards_number);

    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }
    // deck of cards
    doubly_linked_list_t *cards_dll = dll_create(sizeof(dll_node_t));

    for (int i = 0; i < cards_number; i++) {
        type type;
        scanf("%d ", &type.value);
        scanf("%s", type.symbol);
        // check for invald commands
        check();
        if ((strcmp(type.symbol, "HEART") == 0 ||
        strcmp(type.symbol, "SPADE") == 0 ||
        strcmp(type.symbol, "DIAMOND") == 0 ||
        strcmp(type.symbol, "CLUB") == 0) &&
        type.value < 15 && type.value >= 0) {
            // add card to the deck
            dll_add_nth_node(cards_dll, cards_dll->size, &type);

        } else {
            // if the added card is incorrect, we give it another shot
            printf("The provided card is not a valid one.\n");
            i--;
        }
    }
    // add created deck to the deck of decks
    dll_add_nth_node(deck_dll, deck_dll->size, cards_dll);
    free(cards_dll);

    printf("The deck was successfully created with %d cards.\n", cards_number);
}

void add_cards(doubly_linked_list_t *deck_dll) {
    int index_list;
    int cards_number;

    scanf("%d", &index_list);
    scanf("%d", &cards_number);

    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    if (index_list >= deck_dll->size || index_list < 0) {
        printf("The provided index is out of bounds for the deck list.\n");
        return;
    }

    dll_node_t *curr_node_list = dll_get_nth_node(deck_dll, index_list);
    doubly_linked_list_t *list = (doubly_linked_list_t*)curr_node_list->data;

    for (int i = 0; i < cards_number; i++) {
        type type;
        scanf("%d ", &type.value);
        scanf("%s", type.symbol);
        // check for invald commands
        check();
        if ((strcmp(type.symbol, "HEART") == 0 ||
        strcmp(type.symbol, "SPADE") == 0 ||
        strcmp(type.symbol, "DIAMOND") == 0 ||
        strcmp(type.symbol, "CLUB") == 0) &&
        type.value < 15 && type.value >= 0) {
            // add card to the deck
            dll_add_nth_node(list, list->size, &type);

        } else {
            printf("The provided card is not a valid one.\n");
            i--;
        }
    }

    printf("The cards were successfully added to deck %d.\n", index_list);
}
