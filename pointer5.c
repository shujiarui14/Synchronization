#include <stdio.h>

//计算器--可以用switch
/*
int add(int x,int y)
{
    return x+y;
}
int sub(int x,int y)
{
    return x-y;
}
int mul(int x,int y)
{
    return x*y;
}
int div(int x,int y)
{
    return x/y;
}
int main()
{
    int a=9,b=7;
    int (*pf[4])(int ,int)={add,sub,mul,div};
    int i=0;
    for(;i<4;i++)
    {
        printf("%d  ",pf[i](a,b));
        printf("i=%d\n",i);
    }
    return 0;
}

char* (*pf)(char* ,char*)
char* (*pfarr[4])(char*,char*)
*/

//利用函数指针数组的案例
/*
int add(int x,int y)
{
    return x+y;
}
int sub(int x,int y)
{
    return x-y;
}
int mul(int x,int y)
{
    return x*y;
}
int div(int x,int y)
{
    return x/y;
}


void menu()
{
    printf("********************************\n");
    printf("****     1.加法   2.减法     ****\n");
    printf("****     3.乘法   4.除法     ****\n");
    printf("****          0.退出        ****\n");
    printf("********************************\n");
    printf("***********  请选择  ***********\n");
}
int main()
{
    menu();
    int input;
    int x,y;
    int (*pfarr[4])(int ,int)={add,sub,mul,div};
    do
    {scanf("%d",&input);
    if(input>=1)
    {
        printf("请输入两个操作数！");
        scanf("%d %d",&x,&y);
        printf("结果为：%d\n",(*(pfarr+input-1))(x,y));//(*(pfarr+input-1))加括号和不加括号到底有什么区别
    }
    else if(input==0)
    {
        printf("已退出！\n");
    break;
    }
    else
    printf("参数错误，请重新输入！\n");
    }while(input);
}
*/

// int main()
// {
//     int arr[]={0};
//     int* p;
//     int *p1;
//     p=arr;
//     // p1=&arr;
//     // printf("p=%p p1%p",p,p1);
//     return 0;
// }

//回调函数
void print(char *str)
{
    printf("hello,%s\n",str);
}
void test(void (*p)(char *))
{
    printf("test\n");
    p("Narcissus");
}
int main()
{
    test(print);
    return 0;
}