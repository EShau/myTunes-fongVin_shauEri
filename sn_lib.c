#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sn_lib.h"

int let_to_num(char ch) {
        int c = ((int) ch) - 65;
        if ((c >= 0) && (c < 26)) return c;
        else return 26;
}

void add_song(struct song_node *table[27], char *artist, char *name) {
        int i = let_to_num(artist[0]);
        table[i] = insert_order(table[i], artist, name);
}

void print_library(struct song_node *table[27]) {
        for (int i = 0; i < 27; i++) {
                if (table[i] != NULL) {
                        printf("%c list\n", i + 65);
                        print_list(table[i]);
                }
        }
}

void print_letter(struct song_node *table[27], char letter) {
        int i = let_to_num(letter);
        print_list(table[i]);
}

struct song_node *search_song(struct song_node *table[27], char *artist, char *name) {
        int letter = let_to_num(artist[0]);
        return find_song(table[letter], artist, name);
}

struct song_node *search_artist(struct song_node *table[27], char *artist) {
        int letter = let_to_num(artist[0]);
        return find_first_song(table[letter], artist);
}

struct song_node *shuffle(struct song_node *table[27]) {
        int rng = rand() % 27;
        for (; rng < rng + 27; rng++) {
                if (table[rng % 27]) {
                        return random_song(table[rng % 27]);
                }
        }
        return NULL;
}

void remove_songlib(struct song_node *table[27], char *artist, char *name) {
        int i = let_to_num(artist[0]);
        table[i] = remove_song(table[i], artist, name);
}

void free_library(struct song_node *table[27]) {
        for (int i = 0; i < 27; i++) {
                if (table[i]) {
                        table[i] = free_list(table[i]);
                }
        }
}
