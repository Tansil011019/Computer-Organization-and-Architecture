#include <stdio.h>
#include <stdlib.h>

int gura(int x, int y){
    return ~(~x&~y);
    //Hukum DeMorgan
}

int rushia(void){
    return 1<<31;
    //2^-31
}

unsigned int kobokan(unsigned int x, unsigned int n){
    // return ((x>>n)<<n)^x;
    return (x&(1<<n)+(~1+1));
    //Div^x
}

int fauna(int x, int y){
    return(((0xFF<<(y<<3))&x)>>(y<<3))&0xFF;
}

int yamada(int x){
    //first number greater than second number --> second number - first number > 0
    return (((134+(~x+1))>>31)&1)&(((x+(~183+1))>>31)&1);
}

int pekora(int x){
    int first = (x<<24)&(0xFF<<24);
    int second= (0xFF<<16)&(x<<8);
    int third= (0xFF<<8)&(x>>8);
    int forth= (0xFF)&(x>>24);
    return forth|third|second|first;
}

int mumei(int x, int n){
    return (x>>n)&~((((0x1<<31))>>n)<<1);    
}

int moona(int x){
    int count = 32;
    int temp = x;
    temp = temp & (~x+1);
    count = ((~(!!temp)+1)&(~1+1))+count;
    printf("%d\n", count);
    count = ((~(!!(temp & 0x0000FFFF))+1)&(~16+1))+count;
    printf("%d\n", count);
    count = ((~(!!(temp & 0x00FF00FF))+1)&(~8+1))+count;
    printf("%d\n", count);
    count = ((~(!!(temp & 0x0F0F0F0F))+1)&(~4+1))+count;
    printf("%d\n", count);
    count = ((~((!!(temp & 0x33333333)<<1))+1))+count;
    // printf("%d\n", (~(x & 0x33333333)+1));
    printf("%d\n", count);
    count = ((~(!!(temp & 0x55555555))+1))+count;
    printf("%d\n", count);
    return count;
}

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

unsigned int ollie(unsigned int a){
    // unsigned int b= a&1;
    // a=a>>1;
    // a = (a >> 16) + (a & 0xFFFF);
    // a = (a >>  8) + (a & 0xFF); 
    // a = (a >>  4) + (a & 0xF);
    // int greater_condition= ~(((14+(~a+1))>>31)&1)+1;
    // // int temp = a + (~15+1);
    // a=(greater_condition&(~15+1))+a;
    // return b+(a<<1);

    unsigned int mod2_result = a&1;
    a = a>>1;
    a = (a&15) + (a>>4);
    a = (a&15) + (a>>4);
    a = (a&15) + (a>>4);
    a = (a&15) + (a>>4);
    a = (a&15) + (a>>4);
    a = (a&15) + (a>>4);
    a = (a&15) + (a>>4);
    a = (a+((a+1)>>4))&15;
    return mod2_result + (a<<1);
}

unsigned coco(unsigned uf){
    unsigned first_sign, second_exp, third_remain;
    first_sign = uf & (1<<31);
    second_exp = ((uf<<1)>>24) & 255;
    third_remain =  uf & 0x007FFFFF;
    if(second_exp == 0){
        return (uf<<1)+first_sign;
    }else if((second_exp + 1)>>8){
        return uf;
    }else{
        return ((second_exp+1)<<23)+first_sign+third_remain;
    }
}