#include "sn_list.h"

void add_song(struct song_node *table[27], char *name, char *artist);
void print_library(struct song_node *table[27]);
void print_letter(struct song_node *table[27], char letter);
struct song_node *search_song(struct song_node *table[27], char *artist, char *name);
