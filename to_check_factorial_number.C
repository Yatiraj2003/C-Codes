#include<stdio.h>
main()
{
    int N,i,f=1;
    printf("Enter the integer\n");
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        f=f*i;}
        printf("factorial is %d is %d",N,f);

}
