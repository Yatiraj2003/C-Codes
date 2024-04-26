#include<stdio.h>
main()
{
    int N,digit,reverse=0,temp;
    printf("Enter a 3 digit number\n");
    scanf("%d",&N);
    temp=N;
    for(int i=0;i<N;i++)
    {
        digit=N%10;
        reverse=reverse*10+digit;
        N=N/10;
    }
    printf("reverse of a given number is= %d\n",reverse);

    if(temp==reverse)
    {
        printf("%d is the palindrome number\n");
    }
    else
    {
        printf("%d is not a palindrome number\n");
    }

}
