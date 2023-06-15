#include <stdio.h>
#define N 6
#define M 6
void display(int x,int y,int arr[x][y])
{
    int i=0,j=0;
    printf("地址为：\n");
    for(;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("arr[%d][%d]:%p  ",i,j,&arr[i][j]);
        }
        printf("\n");
    }
    printf("值为：\n");
     for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("arr[%d][%d]:%d  ",i,j,arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int arr[N][M]={1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6};
    int i=0,j=0;
    display(N,M,arr);
    int *p=*arr,*p1=arr[1];
    for(;i<N;i++)
    {
        printf("%p\n",p+i);
    }
    printf("\n");
    for(i=0;i<N;i++)
    {
        printf("%p\n",p1);
        p1++;
    }
    return 0;
}