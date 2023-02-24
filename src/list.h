#ifndef __LIST__
#define __LIST__

struct cell_t {
  void* val;
  unsigned long int id;
  struct cell_t* next;
};

typedef struct cell_t* list_t;

list_t list_empty();
int list_is_empty(list_t);
list_t list_push(list_t, void*);
list_t list_tail(list_t);
void* list_pop(list_t*);
void* list_top(list_t);
void list_destroy(list_t, void (*free)(void*));
void* list_in(list_t, void*, int (*eq)(void*, void*));
unsigned long int list_len(list_t);

#endif
