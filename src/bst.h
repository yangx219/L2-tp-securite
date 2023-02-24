#ifndef __BST__
#define __BST__

struct node_t {
  unsigned long int key;
  void* val;
  struct node_t* left;
  struct node_t* right;
};

typedef struct bst_t {
  unsigned long int size;
  struct node_t* tree;
} bst_t;

unsigned long int hash(void*);
bst_t bst_empty(void);
int bst_is_empty(bst_t);
bst_t bst_add(bst_t, void*);
void bst_destroy(bst_t, void (*free_void)(void*));
int bst_in(bst_t, void*);
unsigned long int bst_size(bst_t);

#endif
