#define N 5757

void init();
void print_five_chars(char *);
void print_word(int);
int search_index(char *);


struct node {
  int index;
  struct node * next;
};

extern struct node * adj_list[N];

struct node * new_node();
void free_node(struct node *);
