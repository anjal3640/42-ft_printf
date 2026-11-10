#include"ft_printf.h"
#include<stdio.h>
#include<stdlib.h>

int main(void){
    char c='C';
    char *ptr="hi" ;
    int i=-2147483648;
    int len=ft_printf("hello %c %s %d %d %x %X %X %p\n",c,ptr,i,2147483647,177,177,421,&ptr);
    int oglen=ft_printf("1234567  % d",len);
    printf("   %d",oglen);
}