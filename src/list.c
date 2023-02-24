struct cell_t {
  void* val;
  unsigned long int id;
  struct cell_t* next;
};

typedef struct cell_t* list_t;

list_t list_empty(){
}

int list_is_empty(list_t l){
}

list_t list_push(list_t l, void* x){
}

list_t list_tail(list_t l){
}

void* list_pop(list_t* l){ 
}

void* list_top(list_t l){
}

void list_destroy(list_t l, void (*free)(void*)){
}

// return the found element or NULL
void* list_in(list_t l, void* x, int (*eq)(void*, void*)){
}

unsigned long int list_len(list_t l){
}

