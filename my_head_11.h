#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
// void change(int &x, int &y)
// {
//     x = x ^ y;
//     y = x ^ y;
//     x = x ^ y;
// }

void  test()
{
    double r=0,sum=0,*p=NULL;
    printf("r=%p sum =%p p=%p\n",r,sum,p);
    p=&r;
    printf("r=%p sum =%p p=%p\n",r,sum,p);
    p=&sum;
    printf("r=%p sum =%p p=%p\n",r,sum,p);
    p=&r;
    scanf("%lf",p);
    printf("r=%f sum=%f\n",r,sum);
    p=&sum;
    scanf("%lf",p);
    printf("r=%f sum=%f\n",r,sum);


}

float av(float arr[100],int x)
{
    int k=0;
    float sum=0;
    for(;k<x;k++)
    {
        sum+=arr[k];
    }
    return sum/k;
}

void my_rand(int x,int arr[x])
{
    int i=0,*p;
    srand((unsigned)time(NULL));
    for(;i<x;i++)
    {
        p=&arr[i];
        *p=rand()/1000;
        // printf("%d  ",arr[i]);
    }
}

int* my_max(int x,int arr[x])
{
  
    int max=arr[0],i=0;
      int *p=&max;
      for(;i<x;i++)
      {
        if(arr[i]>*p)
        {
            *p=arr[i];
        }
      }
    return p;
}

void nizi(int x,int arr[x])
{
    int *p,tmp;
    int i=0,j=x-1;
    for(;i<=j;i++,j--)
    {
      tmp=arr[i];  
      p=&arr[i];
      *p=arr[j];
      arr[j]=tmp;
    }
}

int* av1(int x,int arr[x])
{
    int sum=0;
    int *ave=NULL,*p;
    for(int i=0;i<x;i++)
    {
        p=&arr[i];
        sum+=*p;
    }
    ave=&sum;
    *ave/=x;
    return ave;
}


int jiou (int x,int arr[x],int array[x])
{
    int i=0,*p,counter=0,t=0;
    for(;i<x;i++)
    {
        p=&arr[i];
        if(arr[i]%2==0)
        {
            array[t]=*p;
            counter+=1;
            t++;
        }
    }
    return counter;
}

void change_var(int arr[])
{
   int tmp=0;
   tmp=arr[0];
   arr[0]=arr[1];
   arr[1]=tmp;
}