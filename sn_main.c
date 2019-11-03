#include "sn_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(NULL));
  struct song_node * test_sn_list = NULL;
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
  if (song != NULL){
    printf("Song found!: [");
    print_song(song);
    printf("]\n");
  }
  else{
    printf("Uh oh! Song not found!\n");
  }
  printf("Looking for: [Imagine Dragons: Radioactive]\n");
  song = find_song(test_sn_list, "Imagine Dragons", "Radioactive");
  if (song != NULL){
    printf("Song found!: [");
    print_song(song);
    printf("]\n");
  }
  else{
    printf("Uh oh! Song not found!\n");
  }
  printf("Looking for: [Avicii: Heaven]\n");
  song = find_song(test_sn_list, "Avicii", "Heaven");
  if (song != NULL){
    printf("Song found!: [");
    print_song(song);
    printf("]\n");
  }
  else{
    printf("Uh oh! Song not found!\n");
  }
  printf("\n");


  printf("Testing out find_first_song:\n");
  printf("Looking for artist: [Alan Walker]\n");
  song = find_first_song(test_sn_list, "Alan Walker");
  if (song != NULL){
    printf("Song found!: ");
    print_list(song);
  }
  else{
    printf("Uh oh! Artist not found!\n");
  }
  printf("Looking for artist: [Imagine Dragons]\n");
  song = find_first_song(test_sn_list, "Imagine Dragons");
  if (song != NULL){
    printf("Song found!: ");
    print_list(song);
  }
  else{
    printf("Uh oh! Artist not found!\n");
  }
  printf("Looking for artist: [M. Maggie]\n");
  song = find_first_song(test_sn_list, "M. Maggie");
  if (song != NULL){
    printf("Song found!: ");
    print_list(song);
  }
  else{
    printf("Uh oh! Artist not found!\n");
  }
  printf("Looking for artist: [George Bush]\n");
  song = find_first_song(test_sn_list, "George Bush");
  if (song != NULL){
    printf("Song found!: ");
    print_list(song);
  }
  else{
    printf("Uh oh! Artist not found!\n");
  }
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
  printf("List after freeing:");
  print_list(test_sn_list);
  printf("\n");

}