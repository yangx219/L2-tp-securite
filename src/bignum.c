#include <stdlib.h>
#include <gmp.h>

typedef mpz_t* bignum_t;

bignum_t bignum_zero(){
  bignum_t x = (bignum_t) malloc(sizeof(mpz_t));
  mpz_init(*x);
  return x;
}

bignum_t bignum_from_int(int n){
  bignum_t x = (bignum_t) malloc(sizeof(mpz_t));
  mpz_init_set_si(*x, (signed long int) n);
  return x;
}

bignum_t bignum_copy(bignum_t x){
  bignum_t y = bignum_zero();
  mpz_set(*y, *x);
  return y;
}

void bignum_destroy(bignum_t x){
  mpz_clear(*x);
  free(x);
}

int bignum_eq(bignum_t a, bignum_t b){
  return mpz_cmp(*a, *b) == 0;
}

int bignum_lte(bignum_t a, bignum_t b){
  return mpz_cmp(*a, *b) <= 0;
}


int bignum_lt(bignum_t a, bignum_t b){
  return mpz_cmp(*a, *b) < 0;
}


int bignum_gt(bignum_t a, bignum_t b){
  return mpz_cmp(*a, *b) > 0;
}

int bignum_gte(bignum_t a, bignum_t b){
  return mpz_cmp(*a, *b) >= 0;
}

bignum_t bignum_add(bignum_t a, bignum_t b){
  bignum_t x = bignum_zero();
  mpz_add(*x, *a, *b);
  return x;
}
  
bignum_t bignum_sub(bignum_t a, bignum_t b){
  bignum_t x = bignum_zero();
  mpz_sub(*x, *a, *b);
  return x;
}

bignum_t bignum_mul(bignum_t a, bignum_t b){
  bignum_t x = bignum_zero();
  mpz_mul(*x, *a, *b);
  return x;
}

bignum_t bignum_div(bignum_t a, bignum_t b){
  bignum_t x = bignum_zero();
  mpz_div(*x, *a, *b);
  return x;
}

bignum_t bignum_mod(bignum_t a, bignum_t b){
  bignum_t x = bignum_zero();
  mpz_mod(*x, *a, *b);
  return x;
}

bignum_t bignum_powm(bignum_t x, bignum_t n, bignum_t m){
  bignum_t z = bignum_zero();
  mpz_powm(*z, *x, *n, *m);
  return z;
}

bignum_t bignum_pow(bignum_t x, bignum_t exp){
  bignum_t z = bignum_zero();
  unsigned long int e = mpz_get_ui(*exp);
  mpz_pow_ui(*z, *x, e);
  return z;
}

char* bignum_to_str(bignum_t x){
  return mpz_get_str(NULL, 10, *x);
}
