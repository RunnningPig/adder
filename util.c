#include "util.h"

/* 将字符'0'或'1'转换成比特 */
inline bit_t char2bit(char ch){
    return (ch == '0') ? BIT_ZERO : BIT_ONE;
}

/* 将比特转换成字符'0'或'1' */
inline char bit2char(bit_t b){
    return (b == BIT_ZERO) ? '0' : '1';
}

/* 将 01 字符串转换成比特串 */
bit_t *str2bits(bit_t bits[], const char *str){
    for(int i = 0; str[i] != '\0'; i++){
        bits[i] = char2bit(str[i]);
    }
    return bits;
}

/* 将比特串转换成 01 字符串 */
char *bits2str(char *str, const bit_t bits[], word_size_t len){
    for(int i = 0; i < len; i++){
        str[i] = bit2char(bits[i]);
    }
    str[len] = '\0';
    return str;
}

/* 将整数转换成比特串 */
bit_t *uint2bits(bit_t bits[], uintmax_t num, word_size_t len){
    for(int i = 0; i < len; i++){
        bits[i] = isset(num, i) ? BIT_ONE : BIT_ZERO;
    }
    return bits;                    
}

/* 将比特串转换成整数 */
uintmax_t bits2uint(const bit_t bits[], word_size_t len){
    uintmax_t num = 0;
    for(int i = 0; i < len; i++){
        if(bits[i] == BIT_ONE){
            setbit(num ,i);
        }
    }
    return num;
}

/* 打印比特串
**
**       高       低
**        ↓       ↓
** 例如："0110 0110"
*/
void print_bits(const bit_t bits[], word_size_t len){
    while(--len){
        putchar(bit2char(bits[len]));
        if((len&0x03) == 0){
            putchar(' ');
        }
    }
    putchar(bit2char(bits[0]));
}

/* 以竖式计算格式打印
** 例如：
**    0110 0110 (102) →A
** +  1010 0101 (165) →B
** ------------
**  1 0000 1011 (267) →S
**  ↓
**  CO
*/
void print_columnar_addition(const bit_t A[], \
                             const bit_t B[], \
                             const bit_t S[], \
                             bit_t CO, \
                             word_size_t len){
    printf("   ");
    print_bits(A, len);
    printf(" (%lu)\n", bits2uint(A, len));
    
    printf("+  ");
    print_bits(B, len);
    printf(" (%lu)\n", bits2uint(B, len));
    
    printf("---");
    for(int i = 0; i < len+(len>>2)-1; i++) putchar('-');
    putchar('\n');
    
    printf(" %c ", bit2char(CO));
    print_bits(S, len);
    printf(" (%lu)\n", bits2uint(S, len) + CO*(1L<<len));
}