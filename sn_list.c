#include "sn_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node * insert_front(struct song_node * front, char artist[100], char name[100]){
  struct song_node * new_front = malloc(sizeof(struct song_node));
  strcpy(new_front->artist, artist);
  strcpy(new_front->name, name);
  new_front->next = front;
  return new_front;
}

struct song_node * insert_order(struct song_node * front, char artist[100], char name[100]){
  struct song_node * previous = NULL;
  struct song_node * current = front;
  while (current != NULL){
    if (strcmp(current->artist, artist) > 0){
      break;
    }
    if (strcmp(current->artist, artist) == 0){
      if (strcmp(current->name, name) > 0){
        break;
      }
    }
    previous = current;
    current = current->next;
  }
  struct song_node * pointer = insert_front(current, artist, name);
  if (previous != NULL){
    previous->next = pointer;
    return front;
  }
  return pointer;
}

void print_song(struct song_node * node){
  printf("%s: %s", node->artist, node->name);
}

void print_list(struct song_node * front){
  printf("[");
  struct song_node * current = front;
  while (current != NULL){
    print_song(current);
    if (current->next != NULL){
      printf(" | ");
    }
    current = current->next;
  }
  printf("]\n");
}

struct song_node * find_song(struct song_node * front, char artist[100], char name[100]){
  struct song_node * current = front;
  while (current != NULL){
    if (strcmp(current->artist, artist) == 0 && strcmp(current->name, name) == 0){
      break;
    }
    current = current->next;
  }
  return current;
}

struct song_node * find_first_song(struct song_node * front, char artist[100]){
  struct song_node * current = front;
  while (current != NULL){
    if (strcmp(current->artist, artist) == 0){
      break;
    }
    current = current->next;
  }
  return current;
}

struct song_node * random_song(struct song_node * front){
  struct song_node * find_length = front;
  int len = 0;
  while (find_length != NULL){
    len++;
    find_length = find_length->next;
  }
  int random = rand() % len;
  struct song_node * current = front;
  int i;
  for (i = 0; i < random; i++){
    current = current->next;
  }
  return current;
}

struct song_node * remove_song(struct song_node * front, char artist[100], char name[100]){
  struct song_node * previous = NULL;
  struct song_node * current = front;
  while (current != NULL){
    if (strcmp(current->artist, artist) == 0 && strcmp(current->name, name) == 0){
        break;
      }
    previous = current;
    current = current->next;
  }
  if (current != NULL){
    if (previous != NULL){
      previous->next = current->next;
    }
    else{
      front = current->next;
    }
    free(current);
  }
  else{
    printf("[");
    printf("%s: %s", artist, name);
    printf("] not found!\n");
  }
  return front;
}

struct song_node * free_list(struct song_node * front){
  while (front != NULL){
    printf("Freeing: [");
    print_song(front);
    printf("]\n");
    front = remove_song(front, front->artist, front->name);
  }
  return front;
}
