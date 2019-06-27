#include "adder.h"

/* 半加器：一个异或门 + 一个与门 */
void halfadder(bit_t A, bit_t B, bit_t *S, bit_t *CO){
    XOR(A, B, S);
    AND(A, B, CO);
}

/* 全加器：两个半加器 + 一个或门 */
void fulladder(bit_t A, bit_t B, bit_t CI, bit_t *S, bit_t *CO){
    bit_t CO1_tmp, CO2_tmp;
    bit_t S_tmp;
    
    halfadder(A, B, &S_tmp, &CO1_tmp);
    halfadder(CI, S_tmp, S, &CO2_tmp);
    OR(CO1_tmp, CO2_tmp, CO);
}

/* 8位加法器：八个 1 位全加器 */
void adder_8bit(const bit_t A[WS_8], const bit_t B[WS_8], bit_t CI, bit_t S[WS_8], bit_t *CO){
    fulladder(A[0], B[0], CI, &S[0], CO);
    for(int i = 1; i < WS_8; i++){
        fulladder(A[i], B[i], *CO, &S[i], CO);
    }
}

/* 16位加法器：两个 8 位加法器 */
void adder_16bit(const bit_t A[WS_16], const bit_t B[WS_16], bit_t CI, bit_t S[WS_16], bit_t *CO){
    adder_8bit(&A[0], &B[0], CI, &S[0], CO);
    adder_8bit(&A[WS_8], &B[WS_8], *CO, &S[WS_8], CO);
}

/* 32位加法器：两个 16 位加法器 */
void adder_32bit(const bit_t A[WS_32], const bit_t B[WS_32], bit_t CI, bit_t S[WS_32], bit_t *CO){
    adder_16bit(&A[0], &B[0], CI, &S[0], CO);
    adder_16bit(&A[WS_16], &B[WS_16], *CO, &S[WS_16], CO);
}