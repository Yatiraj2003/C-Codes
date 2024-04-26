#include<stdio.h>
main()
{int n1,n2,*p1,*p2;
p1=&n1;
p2=&n2;
    printf("Enter the range to be checked\n");
    scanf("%d %d",p1,p2);
   for(int j=*p1;j<=*p2;j++)
    {int k=0;
        for(int i=1;i<=j;i++)
        {
            if(j%i==0)
                k++;
        }
        if(k==2)
        {
            printf("%d is a prime number\n",j);
        }


    }
}
