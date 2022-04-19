// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort_deck.h"
#include "list.h"
#include "function.h"

int check_symbol(char *symbol)
{
    if (strcmp(symbol, "HEART") == 0) {
        return 0;

    } else if (strcmp(symbol, "SPADE") == 0) {
        return 1;

    } else if (strcmp(symbol, "DIAMOND") == 0) {
        return 2;

    } else {
        return 3;
    }
}

void sort_deck(doubly_linked_list_t *deck_dll)
{
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

    dll_node_t *curr_node_list = dll_get_nth_node(deck_dll, index);
    doubly_linked_list_t *list = (doubly_linked_list_t*)curr_node_list->data;

    dll_node_t *node1 = (dll_node_t*)list->head;
    dll_node_t *node2;

    dll_node_t *aux = NULL;

    int n = list->size;
    int m = list->size - 1;
    // firstly, we sort by number
    while (n) {
        node2 = node1->next;
        while (m) {
                if (((type*)node1->data)->value > ((type*)node2->data)->value) {
                aux = node1->data;
                node1->data = node2->data;
                node2->data = aux;
            }
            node2 = node2->next;
            m--;
        }
        n--;
        m = n - 1;
        node1 = node1->next;
    }
    // now we sort by symbol
    node1 = list->head;
    n = list->size;
    m = list->size - 1;

    while (n) {
        node2 = node1->next;
        while (m) {
                if (((type*)node1->data)->value == ((type*)node2->data)->value)
                {
                    int a = check_symbol(((type*)node1->data)->symbol);
                    int b = check_symbol(((type*)node2->data)->symbol);
                    if (a > b) {
                        aux = node1->data;
                        node1->data = node2->data;
                        node2->data = aux;
                    }
            }
            node2 = node2->next;
            m--;
        }
        n--;
        m = n - 1;
        node1 = node1->next;
    }

    printf("The deck %d was successfully sorted.\n", index);
}
