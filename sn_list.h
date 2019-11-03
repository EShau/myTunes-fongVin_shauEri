struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};
struct song_node * insert_front(struct song_node * front, char artist[100], char name[100]);;
struct song_node * insert_order(struct song_node * front, char artist[100], char name[100]);
void print_song(struct song_node * node);
void print_list(struct song_node * front);
struct song_node * find_song(struct song_node * front, char artist[100], char name[100]);
struct song_node * find_first_song(struct song_node * front, char artist[100]);
struct song_node * random_song(struct song_node * front);
struct song_node * remove_song(struct song_node * front, char artist[100], char name[100]);
struct song_node * free_list(struct song_node * front);
