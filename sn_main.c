#include "sn_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void song_exist(struct song_node * s) {
        if (s){
          printf("Song found!: [");
          print_song(s);
          printf("]\n");
        }
        else printf("Uh oh! Song not found!\n");
}

void artist_exist(struct song_node * s) {
        if (s){
          printf("Artist found!: ");
          print_list(s);
        }
        else printf("Uh oh! Artist not found!\n");
}

int main(){
  srand(time(NULL));
  struct song_node * test_sn_list = NULL;
  printf("\nLIST TESTING\n");
  printf("Testing out print_list (and also print_song), insert_order, and insert_front:\n");
  printf("Printing an empty song list:\n");
  print_list(test_sn_list);
  test_sn_list = insert_order(test_sn_list, "Avicii", "Waiting for Love");
  test_sn_list = insert_order(test_sn_list, "Alan Walker", "Faded");
  test_sn_list = insert_order(test_sn_list, "Imagine Dragons", "Demons");
  test_sn_list = insert_order(test_sn_list, "The Eden Project", "XO");
  test_sn_list = insert_order(test_sn_list, "Aaron Smith", "Dancin");
  test_sn_list = insert_order(test_sn_list, "Avicii", "The Nights");
  test_sn_list = insert_order(test_sn_list, "Lucian", "Down the Middle");
  test_sn_list = insert_order(test_sn_list, "M. Maggie", "Trndsttr");
  test_sn_list = insert_order(test_sn_list, "Imagine Dragons", "Radioactive");
  test_sn_list = insert_order(test_sn_list, "Alan Walker", "Alone");
  test_sn_list = insert_order(test_sn_list, "Alan Walker", "Sing Me to Sleep");
  printf("Printing out a populated, ordered song list:\n");
  print_list(test_sn_list);
  printf("\n");


  printf("Testing out find_song:\n");
  printf("Looking for: [Aaron Smith: Dancin]\n");
  struct song_node * song = find_song(test_sn_list, "Aaron Smith", "Dancin");
  song_exist(song);
  printf("Looking for: [Imagine Dragons: Radioactive]\n");
  song = find_song(test_sn_list, "Imagine Dragons", "Radioactive");
  song_exist(song);
  printf("Looking for: [Avicii: Heaven]\n");
  song = find_song(test_sn_list, "Avicii", "Heaven");
  song_exist(song);
  printf("\n");


  printf("Testing out find_first_song:\n");
  printf("Looking for artist: [Alan Walker]\n");
  song = find_first_song(test_sn_list, "Alan Walker");
  artist_exist(song);
  printf("Looking for artist: [Imagine Dragons]\n");
  song = find_first_song(test_sn_list, "Imagine Dragons");
  artist_exist(song);
  printf("Looking for artist: [M. Maggie]\n");
  song = find_first_song(test_sn_list, "M. Maggie");
  artist_exist(song);
  printf("Looking for artist: [George Bush]\n");
  song = find_first_song(test_sn_list, "George Bush");
  artist_exist(song);
  printf("\n");


  printf("Testing random_song:\n");
  int i;
  for (i = 0; i < 5; i++){
    song = random_song(test_sn_list);
    printf("[");
    print_song(song);
    printf("]\n");
  }
  printf("\n");


  printf("Testing remove_song:\n");
  printf("Removing: [Aaron Smith, Dancin]\n");
  test_sn_list = remove_song(test_sn_list, "Aaron Smith", "Dancin");
  print_list(test_sn_list);
  printf("Removing: [Avicii, The Nights]\n");
  test_sn_list = remove_song(test_sn_list, "Avicii", "The Nights");
  print_list(test_sn_list);
  printf("Removing: [M. Maggie, Trndsttr]\n");
  test_sn_list = remove_song(test_sn_list, "M. Maggie", "Trndsttr");
  print_list(test_sn_list);
  printf("Removing: [The Eden Project, Fumes]\n");
  test_sn_list = remove_song(test_sn_list, "The Eden Project", "Fumes");
  print_list(test_sn_list);
  printf("\n");


  printf("Testing free_list:\n");
  test_sn_list = free_list(test_sn_list);
  printf("List after freeing: ");
  print_list(test_sn_list);

  printf("\nLIBRARY TESTING\n\n");

  struct song_node * table[27];
  for (int i = 0; i < 27; i++) {
          table[i] = NULL;
  }

  add_song(table, "Avicii", "Waiting for Love");
  add_song(table, "Alan Walker", "Faded");
  add_song(table, "Imagine Dragons", "Demons");
  add_song(table, "The Eden Project", "X0");
  add_song(table, "Aaron Smith", "Dancin");
  add_song(table, "Avicii", "The Nights");
  add_song(table, "Lucian", "Down the Middle");
  add_song(table, "M. Maggie", "Trndsttr");
  add_song(table, "Imagine Dragons", "Radioactive");
  add_song(table, "Alan Walker", "Alone");
  add_song(table, "Alan Walker", "Sing Me to Sleep");
  printf("added above songs to library\n");
  printf("printing library\n");
  print_library(table);

  printf("printing lists of library by artist, individually\n");
  printf("\nprinting A-list:\n");
  print_letter(table, 'A');
  printf("printing I-list:\n");
  print_letter(table, 'I');
  printf("printing L-list:\n");
  print_letter(table, 'L');
  printf("printing M-list:\n");
  print_letter(table, 'M');
  printf("printing O-list:\n");
  print_letter(table, 'O');
  printf("printing T-list:\n");
  print_letter(table, 'T');

  printf("\nsearching for songs:\n");
  printf("searching for Alan Walker - Faded:\n");
  song = search_song(table, "Alan Walker", "Faded");
  song_exist(song);
  printf("searching for Imagine Dragons - Radioactive:\n");
  song = search_song(table, "Imagine Dragons", "Radioactive");
  song_exist(song);
  printf("searching for Imagine Dragons - Thunder:\n");
  song = search_song(table, "Imagine Dragons", "Thunder");
  song_exist(song);

  printf("\nsearching for artists:\n");
  printf("searching for Alan Walker:\n");
  song = search_artist(table, "Alan Walker");
  artist_exist(song);
  printf("searching for Imagine Dragons:\n");
  song = search_artist(table, "Imagine Dragons");
  artist_exist(song);
  printf("searching for Drake:\n");
  song = search_artist(table, "Drake");
  artist_exist(song);

  printf("\nfreeing library:\n");
  free_library(table);
  printf("\nlibrary after freeing:\n");
  print_library(table);
  printf("\n");
}
