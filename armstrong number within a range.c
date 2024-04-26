#include<stdio.h>
void Armstrong(int,int);
void Armstrong(int m,int n)
{
    for(int i=m;i<=n;i++)
    {
        int sum=0, temp=i,d;
        while(temp>0)
        {
            d=temp%10;
            sum=sum+(d*d*d);
            temp=temp/10;
        }
        if(sum==i)
        {
            printf("%d is Armstrong Number\n",i);
        }
    }
}
void main()
{
    int a,b;
    printf("Enter the lower and upper limit of range to find Armstrong number\n");
    scanf("%d%d",&a,&b);
    Armstrong(a,b);
}
