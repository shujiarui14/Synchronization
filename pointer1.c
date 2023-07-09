#include <stdio.h>

//指针的大小有些平台是4个字节，有些是八个字节
//字符指针
/*
int main()
{
    char str[]="abcdef";
    char *pc=str;
    printf("%s\n",str);
    printf("%s\n",pc);

    const char *p="abcdef";//常量字符串-const修饰的不能改
    //*p='w';//会出现段错误-因为是常量
    printf("%c\n",*p);//打印出来的是a
    printf("%s\n",*p);//事实上用指针存放字符串只是把字符串第一个字符的地址给了指针
    return 0;
}*/

int main()
{
    char str1[]="abcdef";
    char str2[]="abcdef";
    char* p1="abcdef";
    char* p2="abcdef";
    // *p2='w';
    printf("str1=%p str2=%p\n",str1,str2);
    printf("p1=%p p2=%p\n",p1,p2);
    if(str1==str2)
        printf("hehe\n");
    else
    printf("haha\n");
    if(p1==p2)
        printf("hehe\n");
    else
    printf("haha\n");
    printf("str1=%p str2=%p\n",str1,str2);
    printf("p1=%p p2=%p\n",p1,p2);
    return 0;
}
