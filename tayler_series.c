#include<stdio.h>

int e(int x,int n)
{
    static p=1,f=1;
    int r;
    if(n==0)
       return 1;
    else
    {
       r=e(x,n-1);
       p=p*x;
       f=f*n;
       return r+(p/f);
    }
}

int main()
{
    int x=2;
    printf("%d ",e(x,4));
}
