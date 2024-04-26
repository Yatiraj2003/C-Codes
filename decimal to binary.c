#include<stdio.h>
long binary(int);
main()
{
    int n,y;
    printf("Enter the number\n");
    scanf("%d",&n);
    y=binary(n);
    printf("%d",y);

}
long binary(int n)
{
    int b=0,r,p=1;
    while(n>0)
    {
        r=n%2;
        b=b+r*p;
        p=p*10;
        n=n/2;
    }

    return b;
}
