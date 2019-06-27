#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <string.h>

#include "adder.h"

#define setbit(m, i)    ((m) |= (1L<<(i)))
#define clrbit(m, i)    ((m) &= ~(1L<<(i)))
#define isset(m, i)     (((m)&(1L<<(i))) != 0)
#define isclr(m, i)     (((m)&(1L<<(i))) == 0)

typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned int    uint32_t;
typedef uint32_t        uintmax_t;

bit_t char2bit(char);
char bit2char(bit_t);
bit_t *str2bits(bit_t*, const char*);
char *bits2str(char*, const bit_t*, word_size_t);
bit_t *uint2bits(bit_t*, uintmax_t, word_size_t);
uintmax_t bits2uint(const bit_t*, word_size_t);
void print_bits(const bit_t*, word_size_t);
void print_columnar_addition(const bit_t *A, \
                             const bit_t *B, \
                             const bit_t *S, \
                             bit_t CO, \
                             word_size_t);

#endif