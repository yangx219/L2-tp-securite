#include <assert.h>
#include <stdio.h>
#include "linked_list.h"
#include "bignum.h"

void test_emptyness() {
  assert(list_is_empty(NULL));
  assert(list_is_empty(list_empty()));
  printf("test_emptyness OK\n");
}

void destroy(void* x){
  bignum_destroy((bignum_t) x);
}

int eq(void* x, void* y){
  return bignum_eq((bignum_t) x, (bignum_t) y);
}

void test_push(){
  bignum_t x,y,z;
  list_t l;
  
  x = bignum_from_int(0);
  y = bignum_from_int(1);
  z = bignum_from_int(2);

  l = list_empty();
  l = list_push(l, y);
  l = list_push(l, x);
  l = list_push(l, z);
  
  assert(eq(list_top(l), z));
  assert(eq(list_top(list_tail(l)), x));
  assert(eq(list_top(list_tail(list_tail(l))), y));
  assert(list_is_empty(list_tail(list_tail(list_tail(l)))));
  assert(list_len(l) == 3);
  
  list_destroy(l, &destroy);
  printf("test_push OK\n");
}


void test_top(){
  bignum_t x,y,z;
  list_t l;
  
  x = bignum_from_int(0);
  y = bignum_from_int(1);
  z = bignum_from_int(2);

  l = list_empty();
  l = list_push(l, y);
  assert(eq(list_top(l), y));
  l = list_push(l, x);
  assert(eq(list_top(l), x));
  l = list_push(l, z);
  assert(eq(list_top(l), z));
  
  list_destroy(l, &destroy);
  printf("test_top OK\n");
}


void test_pop(){
  bignum_t x,y,z;
  list_t l;
  
  x = bignum_from_int(0);
  y = bignum_from_int(1);
  z = bignum_from_int(2);

  l = list_empty();
  l = list_push(l, y);
  l = list_push(l, x);
  l = list_push(l, z);

  assert(eq(list_pop(&l), z));
  assert(eq(list_pop(&l), x));
  assert(eq(list_pop(&l), y));
  assert(list_is_empty(l));
  
  list_destroy(l, &destroy);
  printf("test_pop OK\n");
}

void test_in_list(){
  bignum_t x,y,z;
  list_t l;
  
  x = bignum_from_int(0);
  y = bignum_from_int(1);
  z = bignum_from_int(2);

  l = list_empty();
  assert(list_in(l, z, &eq) == 0);
  l = list_push(l, y);
  assert(list_in(l, z, &eq) == 0);
  l = list_push(l, x);
  l = list_push(l, z);

  assert(list_in(l, z, &eq));
  assert(list_in(l, x, &eq));
  assert(list_in(l, y, &eq));
  
  list_destroy(l, &destroy);
  printf("test_in_list OK\n");
}


int main() {
  printf("=== LIST tests ===\n");
  test_emptyness();
  test_push();
  test_top();
  test_pop();
  test_in_list();

  return 0;
}
