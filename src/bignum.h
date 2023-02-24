#ifndef __BIGNUM__
#define __BIGNUM__
#include  <gmp.h>


typedef mpz_t* bignum_t;

bignum_t bignum_zero();
bignum_t bignum_from_int(int);
bignum_t bignum_copy(bignum_t);
void bignum_destroy(bignum_t);

int bignum_eq(bignum_t, bignum_t);
int bignum_lt(bignum_t, bignum_t);
int bignum_lte(bignum_t, bignum_t);
int bignum_gt(bignum_t, bignum_t);
int bignum_gte(bignum_t, bignum_t);

bignum_t bignum_add(bignum_t, bignum_t);
bignum_t bignum_sub(bignum_t, bignum_t);
bignum_t bignum_mul(bignum_t, bignum_t);
bignum_t bignum_div(bignum_t, bignum_t);
bignum_t bignum_mod(bignum_t, bignum_t);
bignum_t bignum_powm(bignum_t, bignum_t, bignum_t);
bignum_t bignum_pow(bignum_t, bignum_t);

char* bignum_to_str(bignum_t);
#endif
