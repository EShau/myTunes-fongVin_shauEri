#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sn_lib.h"

void add_song(struct song_node *table[27], char *artist, char *name) {
        int c = ((int) artist[0]) - 65;
        int i;
        if ((c >= 0) && (c < 26)) i = c;
        else i = 26;
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
        int c = ((char) letter) - 65;
        int i;
        if ((c >= 0) && (c < 26)) i = c;
        else i = 26;
        print_list(table[i]);
}
