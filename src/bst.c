struct node_t {
  unsigned long int key;
  void* val;
  struct node_t* left;
  struct node_t* right;
};

typedef struct bst_t {
  // Use this to compute a key from a val
  // It is not really a hash function, the key must be unique
  unsigned long int (*h)(void*);

  unsigned long int size;
  struct node_t* tree;
} bst_t;

bst_t bst_empty(void){
}

int bst_is_empty(bst_t t){
}

bst_t bst_add(bst_t t, void* x){
}

void bst_destroy(bst_t t, void (*free_void)(void*)){
}

int bst_in(bst_t t, void* x){
}

unsigned long int bst_size(bst_t t){
}
