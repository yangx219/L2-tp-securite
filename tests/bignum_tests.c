#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "bignum.h"

#define BG(n) bignum_from_int(n)

void test_arithmetic(){
  assert(bignum_eq(bignum_add(BG(3), BG(4)), BG(7)));
  assert(bignum_eq(bignum_sub(BG(4), BG(3)), BG(1)));
  assert(bignum_eq(bignum_mul(BG(4), BG(3)), BG(12)));
  assert(bignum_eq(bignum_div(BG(36), BG(6)), BG(6)));
  assert(bignum_eq(bignum_mod(BG(21), BG(4)), BG(1)));
  assert(bignum_eq(bignum_pow(BG(2), BG(10)), BG(1024)));
  assert(bignum_eq(bignum_powm(BG(2), BG(10), BG(7)), BG(2)));
  printf("test_arithmetic OK\n");
}

void test_cmp(){
  assert(bignum_lt(BG(3), BG(42)));
  assert(bignum_lte(BG(3), BG(42)));
  assert(bignum_lte(BG(3), BG(3)));
  assert(!bignum_lte(BG(3), BG(1)));

  assert(!bignum_gt(BG(3), BG(42)));
  assert(!bignum_gte(BG(3), BG(42)));
  assert(bignum_gte(BG(3), BG(3)));
  assert(bignum_gte(BG(3), BG(1)));
  
  printf("test_cmp OK\n");
}

void test_str(){
  assert(strcmp(bignum_to_str(BG(17)), "17") == 0);
  printf("test_str OK\n");
}

int main(){
  printf("=== BIGNUM tests ===\n");
  test_arithmetic();
  test_cmp();
  test_str();

  return 0;
}
  
