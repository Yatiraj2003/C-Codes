#include<stdio.h>
int factorial(int);
main()
{
    int i,n,res;
    printf("Enter a number=\n");
    scanf("%d",&n);
    res=factorial(n);
    printf("%d\n",res);

}
int factorial(int n)
{
    int i,fact=1,sum=0,ans;
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
        ans=fact/i;
        sum=sum+ans;}

    return sum;
}
