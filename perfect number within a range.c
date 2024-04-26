#include<stdio.h>
void strong(int m,int n)
{
    for(int i=m;i<=n;i++)
    {
        int temp=i,sum=0,r,fact,j;
        while(temp>0)
        {   r=temp%10;
              fact=1;
           for(j=r;j>=1;j--)
                {
            fact=fact*j;}



        sum=sum+fact;
            temp=temp/10;}
        if(sum==i)
        {
            printf("%d is the strong number\n",sum);
        }
    }
}

void strong(int,int);
main()
{
    int m,n;
    printf("Enter the lower and upper limit\n");
    scanf("%d %d",&m,&n);
    strong(m,n);
}
