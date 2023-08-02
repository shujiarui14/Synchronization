
#include <stdio.h>
//内置类型-单一对象：char short int long float..
//结构体
//枚举类型
//联合类型

//结构体：1.结构是一些值得集合，这些值称为成员变量。
//       2.结构体得成员可以是不同类型得变量
//定义一个结构体类型
// struct stu//声明一个学生类型，创造一些值来描述这个学生
// {
//     /* data */
//     char name[20];
//     int tel[11];
//     char sex[10];
//     int age;//成员变量

// }s1,s2;//;不能省略

// struct stu s3;//全局结构体变量


// struct 
// {
//     int a,b;
//     float sum;
// }x;//匿名结构体类型，只能在这儿创建变量

// int main()
// {
//     //结构体变量：
//     struct stu s4;  
//     struct stu s5;//局部结构体变量
    
//     return 0;
// }

//结构体内存对齐

struct s1
{
    char a;
    int c;
    char b;
};

struct s2
{
    char a;
    char b;
    int c;
    char d;
    double f;
};
//结构体内存对齐
//第一个成员变量与结构体在与结构体偏移量为0的地址处
//其他成员变量对齐某个对齐数的整数倍的地址处
//对齐数=编译器默认的一个对齐数，VS默认是8，都是没有对齐数=成员变量的较小值
//结构体总大小为为最大对齐数（每个成员变量都有一个对齐数）的整数倍
//#paragma pack(4)修改默认对齐数

int main()
{
    struct s1 s={0};
    struct s2 ss={0};
    printf("%d\n",sizeof(s));
    printf("%d\n",sizeof(ss));
    return 0;
}