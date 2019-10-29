struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};
struct song_node * insert_front(struct song_node * front, char[100] name, char[100] artist);
struct song_node * insert_order(struct song_node * front, char[100] name, char[100] artist);
void insert_order(struct song_node * front);
struct song_node * find_song(struct song_node * front, char[100] name, char[100] artist);
struct song_node * first_song(struct song_node * front, char[100] name);
struct song_node * random_song(struct song_node * front);
struct song_node * remove_song(struct song_node * front, struct song_node * should_remove);
struct song_node * free_list(struct song_node * front);
