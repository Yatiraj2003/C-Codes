#include<stdio.h>
main()
{
    int N,num,even_sum=0,odd_sum=0,i;
    printf("Enter the limit\n");
    scanf("%d",&N);
    printf("Enter %d integer number",N);
    for(i=1;i<=N;i++)
    {
        scanf("%d",&num);
        if(num%2==0)
        {
            even_sum=even_sum+num;
        }
        else
        {
            odd_sum=odd_sum+num;
        }
        printf("sum of even number=%d\n",even_sum);
        printf("sum of odd number=%d\n",odd_sum);
    }
}
