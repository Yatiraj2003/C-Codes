
#include<stdio.h>
main()
{
    int n,a,b,temp,i,r,j,sum=0,fact,*p1,*p2;
    p1=&a;
    p2=&b;
    printf("enter the range=");
    scanf("%d %d",p1,p2);

for(j=*p1;j<=*p2;j++)
{


    sum=0;    temp=j;
  while(temp>0)
{
        fact=1;
        r=temp%10;
        for(i=1;i<=r;i++)
        {
            fact=fact*i;
        }
        sum=sum+fact;

temp/=10;
}
    if(j==sum)


        printf("%d is a strong number\n",j);


}
}
