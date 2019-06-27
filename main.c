#include "adder.h"
#include "util.h"

#define WORDSIZE WS_8  // WS_16 WS_32

int main(){
    bit_t A[WORDSIZE], B[WORDSIZE], S[WORDSIZE], CO;
    
    uint2bits(A, 102, WORDSIZE);
    uint2bits(B, 165, WORDSIZE);
    
    adder_8bit(A, B, BIT_ZERO, S, &CO);
    //adder_16bit(A, B, BIT_ZERO, S, &CO);
    //adder_32bit(A, B, BIT_ZERO, S, &CO);
    
    print_columnar_addition(A, B, S, CO, WORDSIZE);
    
    return 0;
}
