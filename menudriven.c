#include<stdio.h>
int fact(int);
int prime(int);
int oddeven(int);
main()
{
    while(1)
    {
        int num,op,res;
        printf("\nEnter a number\n");
        scanf("%d",&num);
        printf("1: factorial of number\n 2: prime or not\n 3:odd or even\n 4:exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:res=fact(num);
             printf("factorial of %d is %d\n",num,res);
              break;
              case 2 :prime(num);
              break;
              case 3:oddeven(num);
              case 4:exit(0);
              break;
              default :printf("invalid option\n");
              break;
        }
    }

}
int fact(int num)
{
    int i,fact=1;
    for(i=1;i<=num;i++)
    {
        fact=fact*i;
    }
    return fact;

}
int prime(int num)
{
    int i,count=0;
    for(i=1;i<=num;i++)
    {
        if(num%i==0){count++;}
    }
    if(count==2)
        {printf("prime number it is\n");}
    else {printf("not a prime number\n");}
}
int oddeven(num)
{
    if(num%2==0)
        {printf("it is a even number\n");}
    else {printf("odd number it is\n");}
}

