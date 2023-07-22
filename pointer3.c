#include <stdio.h>

// void test(int arr[]){
//     int i=0;
//     for(;i<10;i+=1)
//     {
//         printf("%d ",arr[i] );
//     }
//     }
// void test2(int* arr){
//     int i=0;
//     for(;i<10;i++)
//     {
//         printf("%d ",*(arr+i));
//     }
// }
// void test3(int* arr[10])
// {
//     int i=0;
//     for(;i<10;i++)
//     {
//         printf("%d ",**(arr+i));
//     }
// }

// void test4(int **arr)
// {
//     int i=0;
//     for(;i<10;i++)
//     {
//         printf("%d ",**(arr+i));
//     }
// }
// int main()
// {
//     int a=1,b=2,c=3,d=4,e=5,f=6,g=7,h=8,i=9,j=10;
//     int arr[10]={0,1,2,3,4,5,6,7,8,9};
//     int* arr1[10]={&a,&b,&c,&d,&e,&f,&g,&h,&i,&j};
//     test(arr);
//     printf("\n");
//     test2(arr);
//     printf("\n");
//     test3(arr1);
//     printf("\n");
//     test4(arr1);
//     return 0;
// }


// void test(int (*arr)[5])
// {

// }
// void test1(int **p)
// {
//     printf("p=%p\n",p);
//     printf("p=%p\n",*p);
//     printf("p=%d\n",**p);
// }
// int main()
// {
//     int arr[3][5]={0};
//     test(arr);

//     int a=9;
//     int* p=&a;
//     int** p1=&p;
//     printf("p1=%p\n",p1);
//     printf("p1=%p\n",*p1);
//     printf("p1=%d\n",**p1);
//     test1(p1);
//     return 0;
// }



void test(int (*p)[4])
{
    printf("p=%p\n",p);
    int i=0,j=0;
    for(;i<4;i+=1)
    {
        printf("p=%p\n",*(p+i));
        for(j=0;j<4;j++)
        {
            printf("%d ",*(*(p+i)+j));
        }
        printf("i=%d \n",i);
    }
}
int main()
{
    int arr[4][4]={{0,1,2,3},{1,2,3,4},{2,3,4,5},{3,4,5,6}};
    int a=1,b=2,c=3,d=4,e=5,f=6,g=7,h=8,i=9,j=10;
    int* arr1[10]={&a,&b,&c,&d,&e,&f,&g,&h,&i,&j};
    test(arr);
    return 0;
}