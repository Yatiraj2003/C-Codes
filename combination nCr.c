#include<stdio.h>

int C(int n,int r)
{
    if(r==0 || n==r)
    {
        return 1;
    }
    else
    {
        return C(n-1,r-1)+C(n-1,r);
    }
}

int main()
{
    int n=5,r=3;
    printf("%d ",C(n,r));
}
