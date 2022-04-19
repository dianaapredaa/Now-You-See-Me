# Copyright 2021 - 2022 Preda Diana 314CA

build:
	gcc -g tema1.c add.c del.c count.c show_deck.c sort_deck.c reverse_deck.c split_deck.c merge_decks.c shuffle_deck.c exit.c function.c list.c -lm -Wall -Wextra -std=c99 -o tema1
run:
	valgrind --leak-check=full ./tema1
clean:
	rm -f tema1

