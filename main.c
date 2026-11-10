#include"ft_printf.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(void){
    char c='\0';
    char *ptr="" ;
    int i=-2147483648;
    int len=ft_printf("hello %c %s %d %d %x %X %X %p\n",c,ptr,i,2147483647,177,177,421,&ptr);
    int oglen=ft_printf("1234567  % d",len);
    printf("   %d\n",oglen);

    printf("---------------------------------\n");
    len=ft_printf("for d %d %d %d %d  \n",-1,0,INT_MAX,INT_MIN);
    ft_printf("len=%d\n",len);
    len=printf("for d %d %d %d %d  \n",-1,0,INT_MAX,INT_MIN);
    printf("len=%d\n\n",len);
    len=ft_printf("for i %i %i %i %i  \n",-1,0,INT_MAX,INT_MIN);
    ft_printf("len=%d\n",len);
    len=printf("for i %i %i %i %i  \n",-1,0,INT_MAX,INT_MIN);
    printf("len=%d\n\n",len);
    len=ft_printf("for u %u %u\n",-1,0);
    ft_printf("len=%d\n",len);
    len=printf("for u %u %u\n",-1,0);
    printf("len=%d\n\n",len);
    len=ft_printf("for x %x %x %x %x  \n",-1,0,INT_MAX,INT_MIN);
    ft_printf("len=%d\n",len);
    len=printf("for x %x %x %x %x  \n",-1,0,INT_MAX,INT_MIN);
    printf("len=%d\n\n",len);
    len=ft_printf("for X %X %X %X %X  \n",-1,0,INT_MAX,INT_MIN);
    ft_printf("len=%d\n",len);
    len=printf("for X %X %X %X %X  \n",-1,0,INT_MAX,INT_MIN);
    printf("len=%d\n\n",len);
    len=ft_printf("for u %u %u\n",-1,0);
    ft_printf("len=%d\n",len);
    len=printf("for u %u %u\n",-1,0);
    printf("len=%d\n\n",len);
    len=ft_printf("for p %p %p %p\n",NULL,(void *)-1,&ptr);
    ft_printf("len=%d\n",len);
    len=printf("for p %p %p %p\n",NULL,(void *)-1,&ptr);
    printf("len=%d\n\n",len);
    len=ft_printf("for s %s %s %s\n",(char *)NULL,"hello anjal",ptr);
    ft_printf("len=%d\n",len);
    len=printf("for s %s %s %s\n",(char *)NULL,"hello anjal",ptr);
    printf("len=%d\n\n",len);
    len=ft_printf("for c %c %c %c\n",c,'C',0);
    ft_printf("len=%d\n",len);
    len=printf("for s %c %c %c\n",c,'C',0);
    printf("len=%d\n\n",len);
     len=ft_printf("for %%  ");
    ft_printf("len=%d\n",len);
    len=printf("for %%  ");
    printf("len=%d\n\n",len);

}