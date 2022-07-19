#include <stdio.h>
#include <stdint.h>
#include <stdio.h>
#include "add-nbo.h"

uint32_t add_nbo(uint32_t num1, uint32_t num2){
    uint32_t n1_4 = num1 & 0xff000000;
    uint32_t n1_3 = num1 & 0x00ff0000;
    uint32_t n1_2 = num1 & 0x0000ff00;
    uint32_t n1_1 = num1 & 0x000000ff;
    n1_1 <<= 24;
    n1_2 <<= 8;
    n1_3 >>= 8;
    n1_4 >>= 24;
    uint32_t result1 = n1_1|n1_2|n1_3|n1_4;

    uint32_t n2_4 = num2 & 0xff000000;
    uint32_t n2_3 = num2 & 0x00ff0000;
    uint32_t n2_2 = num2 & 0x0000ff00;
    uint32_t n2_1 = num2 & 0x000000ff;
    n2_1 <<= 24;
    n2_2 <<= 8;
    n2_3 >>= 8;
    n2_4 >>= 24;    
    uint32_t result2 = n2_1|n2_2|n2_3|n2_4;

    printf("%x",result1);
    printf("%x",result2);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",result1,result1,result2,result2,result1+result2,result1+result2);
    return 1;

}