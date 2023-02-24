#include <stddef.h>
#include "list.h"

#define ARRAY_CAPACITY 1 << 16

struct hash_tbl {
  size_t (*h)(void*);
  int (*eq)(void*, void*);
  void (*free)(void*);
  unsigned long int size;
  size_t capacity; // array length
  list_t* array;
};

typedef struct hash_tbl* hash_tbl;

hash_tbl htbl_empty(size_t (*h)(void*),
                    int (*eq)(void*, void*),
                    void (*free)(void*)){
}

int htbl_add(hash_tbl htbl, void* x){
}

int htbl_in(hash_tbl htbl, void* x){
}

void htbl_destroy(hash_tbl htbl){
}
  
