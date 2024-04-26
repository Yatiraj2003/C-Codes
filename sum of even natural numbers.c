#include<stdio.h>
main()
{
    int i,n,sum=0;
    printf("enter the number\n");
    scanf("%d",&n);
    for(i=2;i<=n;i=i+2)
    {
        sum=sum+i;
        printf("%d\n",sum);
    }

}
