#include "my_head_11.h"
#include <stdio.h>
#include<stdlib.h>
//用变量更名交换两个变量
/*
int main()
{
    int a = 1, b = 2;
    printf("交换前：a=%d b=%d\n", a, b);
    change(a, b);
    printf("交换后：a=%d b=%d\n", a,b);
    return 0;
}
*/
//用指针交换两个变量的值
/*
int main()
{
    int a=10,b=20;
    printf("交换前：a=%d b=%d\n",a,b);
    int *p,tmp;
    tmp=b;
    p=&a;
    b=*p;
    *p=tmp;
    a=*p;
    printf("交换后：a=%d b=%d\n",a,b);
    return 0;
}*/

//利用指针来求圆的面积
/*
#define R 3.1415926
int main()
{
    // test();
    double r,sum,*p;
    p=&r;
    printf("请输入圆的半径\n");
    scanf("%lf",p);
    sum=r*r*R;
    printf("圆的面积为：%lf\n",sum);
    return 0;
}
*/

//编写程序，用指针的方法从键盘上输入n（n的值由键盘输入）个数，求n个数的平均数
/*
int main()
{
    float arr[100],*p;
    int i,j=0;
    printf("你要计算几个数？\n");
    // printf("test\n");
    scanf("%d",&i);
    for(;j<i;j++)
    {
        p=&arr[j];
        scanf("%f",p);
        // printf("arr[%d]=%f\n",j,arr[j]);
    }
    printf("%d个数的平均数为：%f\n",i,av(arr,i));
    return 0;
}
*/

//编写程序，求一维数组的最大值（用指针的方法实现）
/*
#define N 20
int main()
{
    int j=0;
    int arr[20]={0};
    printf("随机生成%d个数\n",N);
    my_rand(N,arr);
    for(j=0;j<N;j++)
    {
        printf("%d  ",arr[j]);
    }
    printf("\n最大值为：%d\n",*my_max(N,arr));
    return 0;
}*/

//编写程序，将一维数组中的元素逆置（反序存储）（用指针的方法实现）
/*
#define N 20
int main()
{
    int i=0;
    int arr[N];
    printf("随机生成%d个数 ：\n",N);
    my_rand(N,arr);
    for(;i<N;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n逆置数组为\n");
    nizi(N,arr);
    for(i=0;i<N;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
    return 0;
}
*/

//编写程序，输入出一维数组中大于平均数的数（用指针的方法实现）
/*#define N 10
int main()
{
    int arr[N]={0};
    int i=0,counter=0;
    printf("随机生成%d个数\n",N);
    my_rand(N,arr);
    for(;i<N;i++)
    {
        printf("%d  ",arr[i]);
    }
    int tmp=*av1(N,arr);
    printf("\n大于平均数的有：(平均数是%d)\n",tmp);
    for(i=0;i<N;i++)
    {
        if(arr[i]>tmp)
        {
            printf("%d  ",arr[i]);
            counter++;
        }
    }
    printf("   共%d个\n",counter);

    return 0;
}
*/
//
//编写程序，求一维数组中偶的平方和（用指针的方法实现）
/*
#define N 5
int main()
{
    int arr[N],i=0,array[N];
    long sum=0;
    printf("随机生成%d个数\n",N);
    my_rand(N,arr);
    for(;i<N;i++)
    {
        printf("%d  ",arr[i]);
    }
    int tmp=jiou(N,arr,array);
    printf("\n");
    // for(i=0;i<tmp;i++)
    // {
    //     printf("%d  ",array[i]);
    // }
     for(i=0;i<tmp;i++)
    {
       sum+=(array[i]*array[i]);
    }
    printf("sum=%d\n",sum);
    return 0;
}
*/

//写一个函数，用数组名作为实参的方法交换两个变量的值。
int main()
{
    int arr[2]={13,14};
    printf("交换前：arr[0]=%d arr[1]=%d\n",arr[0],arr[1]);
    change_var(arr);
    printf("交换后：arr[0]=%d arr[1]=%d\n",arr[0],arr[1]);
    return 0;
}

