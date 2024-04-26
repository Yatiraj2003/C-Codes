#include<stdio.h>
main()
{
    int N,F1=-1,F2=+1,F3,i;
    printf("Enter the number\n");
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        F3=F1+F2;
        printf("%d  ",F3);
        F1=F2;
        F2=F3;

    }
}
