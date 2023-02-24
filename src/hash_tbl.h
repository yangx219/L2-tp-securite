#ifndef __HASH_TBL__
#define __HASH_TBL__

#include "linked_list.h"

struct hash_tbl {
  size_t (*h)(void*);
  int (*eq)(void*, void*);
  void (*free)(void*);
  unsigned long int size;
  unsigned long int capacity; // array length
  list_t* array;
};

typedef struct hash_tbl* hash_tbl;

hash_tbl htbl_empty(size_t (*h)(void*),
                    int (*eq)(void*, void*),
                    void (*free)(void*));
int htbl_add(hash_tbl, void*);
int htbl_in(hash_tbl, void*);
void htbl_free(hash_tbl);

#endif
  
