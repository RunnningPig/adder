#ifndef _ADDER_H_
#define _ADDER_H_

#define XOR(A, B, Y) (*(Y) = (A)^(B))
#define AND(A, B, Y) (*(Y) = (A)&(B))
#define  OR(A, B, Y) (*(Y) = (A)|(B))

typedef enum {
    BIT_ZERO = 0,
    BIT_ONE = 1
} bit_t;

typedef enum {
    WS_8 = 8,
    WS_16 = 16,
    WS_32 = 32,
}word_size_t;

void halfadder(bit_t A, bit_t B, bit_t *S, bit_t *CO);
void fulladder(bit_t A, bit_t B, bit_t CI, bit_t *S, bit_t *CO);
void adder_8bit(const bit_t A[WS_8], const bit_t B[WS_8], bit_t CI, bit_t S[WS_8], bit_t *CO);
void adder_16bit(const bit_t A[WS_16], const bit_t B[WS_16], bit_t CI, bit_t S[WS_16], bit_t *CO);
void adder_32bit(const bit_t A[WS_32], const bit_t B[WS_32], bit_t CI, bit_t S[WS_32], bit_t *CO);

#endif