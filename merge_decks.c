// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reverse_deck.h"
#include "list.h"
#include "function.h"

void merge_decks(doubly_linked_list_t *deck_dll) {
    int index_list1, index_list2;

    scanf("%d%d", &index_list1, &index_list2);

    // check for invalid commands
    if (check() == 0) {
		printf("Invalid command. Please try again.\n");
        return;
    }

    if (index_list1 >= deck_dll->size || index_list2 >= deck_dll->size ||
    index_list1 < 0 || index_list2 < 0) {
        printf("The provided index is out of bounds for the deck list.\n");
        return;
    }
    // create new deck
    doubly_linked_list_t *cards_dll = dll_create(sizeof(dll_node_t));

    dll_node_t *node_list1;
    node_list1 = (dll_node_t*)dll_get_nth_node(deck_dll, index_list1);
    doubly_linked_list_t *list1 = (doubly_linked_list_t*)node_list1->data;
    dll_node_t *node1 = (dll_node_t*)list1->head;

    dll_node_t *node_list2;
    node_list2 = (dll_node_t*)dll_get_nth_node(deck_dll, index_list2);
    doubly_linked_list_t *list2 = (doubly_linked_list_t*)node_list2->data;
    dll_node_t *node2 = (dll_node_t*)list2->head;

    int a = list1->size;
    int b = list2->size;
    int c, d;
    int n;
    int i = 0;

    // find common ground
    if (a > b) {
        n = b;
    } else {
        n = a;
    }

    n = n * 2;
    // as long as there are elements in both lists, complete the new deck
    while (n) {
        if (i % 2 == 0) {
            dll_add_nth_node(cards_dll, i, node1->data);
            node1 = node1->next;
            a--;
        } else {
            dll_add_nth_node(cards_dll, i, node2->data);
            node2 = node2->next;
            b--;
        }
        i++;
        n--;
    }

    // if there are any elements left in list1, add them
    while (a) {
        dll_add_nth_node(cards_dll, i, node1->data);
        node1 = node1->next;
        i++;
        a--;
    }

    // if there are any elements left in list2, add them
    while (b) {
        dll_add_nth_node(cards_dll, i, node2->data);
        node2 = node2->next;
        i++;
        b--;
    }

    if (index_list1 > index_list2) {
        c = index_list1;
        d = index_list2;
    } else {
        c = index_list2;
        d = index_list1;
    }
    // delete both (old) decks
    dll_node_t* trash = dll_remove_nth_node(deck_dll, c);
    doubly_linked_list_t* trash_deck = (doubly_linked_list_t*)trash->data;
    dll_free(&trash_deck);
    free(trash);

    dll_node_t* trash2 = dll_remove_nth_node(deck_dll, d);
    doubly_linked_list_t* trash_deck2 = (doubly_linked_list_t*)trash2->data;
    dll_free(&trash_deck2);
    free(trash2);
    // add the new deck to the big deck
    dll_add_nth_node(deck_dll, deck_dll->size, cards_dll);
    free(cards_dll);

    printf("The deck %d and the deck %d were successfully merged.\n",
    index_list1, index_list2);
}
