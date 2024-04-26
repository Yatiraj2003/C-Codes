#include<stdio.h>

void perfect(int m,int n)
{
    for(int i=m;i<=n;i++)
    {
        int temp=i,sum=0,j;
        for(j=1;j<i;j++)
        {
            if(i%j==0)
            {
                sum=sum+j;
            }
        }
        if(sum==i)
        {
            printf("%d is perfect number\n",sum);
        }


    }
}

void perfect(int,int);
main()
{
    int m,n;
    printf("Enter the lower and upper limit of range\n");
    scanf("%d %d",&m,&n);
    perfect(m,n);
}

