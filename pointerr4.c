#include <stdio.h>

int add(int x,int y)
{
    int z=x+y;
    return z;
}
int main()
{
    int a=2,b=3;
    int tmp=add(a,b);
    printf("%d\n",tmp);
    int (*pf)(int ,int)=add;
    tmp=pf(3,4);//add，pf都是地址
    printf("%d\n",(*pf)(3,7));//在调用函数的时候，我们直接写成add(3,5),事实上这儿的add 本身就是个地址
    printf("%d\n",(**pf)(9,7));//那么对他解引用操作和直接使用地址作为函数名没多大的区别
     printf("%d\n",tmp);
    return 0;
}

// int main()
// {
//     void(* signal(int ,void(*)(int)))(int);
//     typedef void(* puf_t)(int);
//     puf_t signal(int ,puf_t);
//     // (*(void (*)()0))();
//     int (*(*v)[])();
//     return 0;
// }