// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "add.h"
#include "del.h"
#include "function.h"
#include "show_deck.h"
#include "count.h"
#include "sort_deck.h"
#include "reverse_deck.h"
#include "split_deck.h"
#include "merge_decks.h"
#include "shuffle_deck.h"
#include "exit.h"

#define AMAX 20

int main(void)
{
	char action[AMAX];

	// the deck of decks
	doubly_linked_list_t* deck_dll;
	deck_dll = dll_create(sizeof(doubly_linked_list_t));

	// we play the game until EXIT command is introduced
	do {
		scanf("%s", action);

		if (strcmp(action, "ADD_DECK") == 0) {
			add_deck(deck_dll);

		} else if (strcmp(action, "ADD_CARDS") == 0) {
			add_cards(deck_dll);

		} else if (strcmp(action, "DEL_DECK") == 0) {
			del_deck(deck_dll);

		} else if (strcmp(action, "DEL_CARD") == 0) {
			del_card(deck_dll);

		} else if (strcmp(action, "DECK_NUMBER") == 0) {
			deck_number(deck_dll);

		} else if (strcmp(action, "DECK_LEN") == 0) {
			deck_len(deck_dll);

		} else if (strcmp(action, "SHOW_DECK") == 0) {
			show_deck(deck_dll);

		} else if (strcmp(action, "SHOW_ALL") == 0) {
			show_all(deck_dll);

		} else if (strcmp(action, "SHUFFLE_DECK") == 0) {
			shuffle_deck(deck_dll);

		} else if (strcmp(action, "MERGE_DECKS") == 0) {
			merge_decks(deck_dll);

		} else if (strcmp(action, "SPLIT_DECK") == 0) {
			split_deck(deck_dll);

		} else if (strcmp(action, "REVERSE_DECK") == 0) {
			reverse_deck(deck_dll);

		} else if (strcmp(action, "SORT_DECK") == 0) {
			sort_deck(deck_dll);

		} else if (strcmp(action, "EXIT") == 0) {
			exit_function(deck_dll);
		} else {
			check();
			printf("Invalid command. Please try again.\n");
		}
	} while (strcmp(action, "EXIT") != 0);

	return 0;
}
