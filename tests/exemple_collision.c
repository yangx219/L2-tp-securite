#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <openssl/md5.h>
#include "list.h"

typedef struct pair_t {
  char x[8];
  unsigned char h;
}* pair_t;

int eq_pair(void* a, void* b){
  return ((pair_t)a)->h == ((pair_t)b)->h;
}

/* char x[8] */
unsigned char md5_first_byte(const char* x){
  unsigned char digest[MD5_DIGEST_LENGTH];
  
  MD5((const unsigned char*)x, 8, digest);
  return digest[0]; // we keep only the first byte
}

int main(){
  pair_t p, q;
  list_t l;
  unsigned int i = 0;

  srand(time(NULL));

  l = list_empty();
  
  for(;;){
    p = (pair_t)malloc(sizeof(struct pair_t));
    for(int i = 0; i < 7; i++)
      p->x[i] = rand() % (126-32-1) + 32;
    p->x[7] = 0;
    p->h = md5_first_byte(p->x);

    if((q = (pair_t)list_in(l, p, eq_pair)) != NULL){
      printf("After %d iterations, a collision happened !\n", i);
      printf("%s and %s have the same MD5 first byte.\n", p->x, q->x);

      return 0;
    } else {
      l = list_push(l, p);
    }
  }
}
    
