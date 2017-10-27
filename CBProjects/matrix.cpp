#include <iostream>
#include <stdio.h>
#include <stdlib.h>
float** func(float **a,float **b,int N);
int main()
{
    int N;
    std::cin>>N;
float **a,**b,**rez;
a = (float **)malloc(N*sizeof(float *));
for(int i=0;i<N;i++)
a[i] = (float *)malloc(N*sizeof(float));


b = (float **)malloc(N*sizeof(float *));
for(int i=0;i<N;i++)
b[i] = (float *)malloc(N*sizeof(float));;


        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++)
        {
            a[i][j]=1;
            b[i][j]=1;
        }


rez = (float **)malloc(N*sizeof(float *));
for(int i=0;i<N;i++)
rez[i] = (float *)malloc(N*sizeof(float));;

    rez = func(a,b,N);
  for(int z=0;z<N;z++)
  {
for(int i = 0;i<N;i++)
    std::cout<<rez[z][i]<<" ";
    std::cout<<std::endl;
  }
}
float** func(float **a,float **b,int N)
{

float **rez;
rez = (float **)malloc(N*sizeof(float *));
for(int i=0;i<N;i++)
rez[i] = (float *)malloc(N*sizeof(float));;
for(int z=0;z<N;z++)
for(int i = 0;i<N;i++)
{int sum =0;
for(int j = 0;j<N;j++)
sum=sum+a[i][j]*b[j][i];
rez[z][i]=sum;
}
    return rez;
}

