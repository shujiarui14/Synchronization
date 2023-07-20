#include <stdio.h>
// int main()
// //指针数组
// {
//     int arr[10]={0};//整型数组--用来存放整型数据
//     char str[10]="abcd";//字符数组--用来存放字符数据
//     int* parr[5];//指针数组--用来存放整型指针的数组
//     char* pstr[5];//指针数组--用来存放字符指针的数组
//     return 0;
// }

//常见用法
// int main()
// {
//     int arr1[]={0,1,2,3,4,5,6};
//     int arr2[]={1,2,3,4,5,6};
//     int arr3[]={2,3,4,5,6,7};

//     int* parr[]={arr1,arr2,arr3};
//     int i=0,j;
//     for(;i<3;i++)
//     {
//         for(j=0;j<7;j++)
//         {
//             printf("%d  ",*(parr[i]+j));
//             //打印出来的结果，如果数组长度不一样，后面的值是未定义
//             // 0  1  2  3  4
//             // 1  2  3  4  5
//             // 2  3  4  5  6
//         }
//         printf("\n");
//     }
//     return 0;
// }


//数组指针--指向数组的指针

// int main()
// {
//     int arr[10]={0};
//     //arr--首元素地址
//     //&arr[0]--首元素的地址
//     //&arr--数组的地址

//     int arr1[10]={0,1,2,3,4,5,6,7,8,9};
//     int (*p)[10]=&arr1;
//     char* str[5];
//     char* (*pa)[5]=&str;
//     return 0;
// }

void print1(int arr[4][5],int x,int y)//这里的传参是数组的形式
{
    int i=0,j=0;
    for(;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
}

void print2(int (*p)[5],int x,int y)//这里的参数是指针
{
    int i=0,j=0;
    for(;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            // printf("%d  ",*(*(p+i)+j));
            printf("%d  ",(*(p+i))[j]);
            // printf("t%d  ",*(p+i));

        }
        printf("\n");
    }
}
int main()
{
    int arr[4][5]={{0,1,2,3,4},{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
    print1(arr,4,5);
    printf("\n");
    print2(arr,4,5);
    int tmp=sizeof(arr);
    printf("tmp=%d\n",tmp);
    // int* p=arr;
    // printf("p=%d\n",*p);
    int arr2[10]={0,1,2,3,4,5,6,7,8,9};
    int* p=arr2;
    int i=0;
    for(;i<10;i++)
    {
        printf("%d  ",arr2[i]);
        printf("%d  ",*(arr2+i));
        printf("%d  ",*(p+i));
    }

    int (*parr[10])[5];//parr是一个数组，里面有10个元素，每个元素放的是数组指针，该数组指针有五个元素，每个元素是int
    return 0;
}

