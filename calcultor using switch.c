#include<stdio.h>
main()
{
    float x,y,result;
    char op;
    printf("enter two numbers\n");
    scanf("%f%f",&x,&y);
    printf("choose operator +,-,*,/\n ");
    scanf(" %c",&op);
    switch(op)
    {
        default: printf("invalid operator\n");
        break;
        case '+':result=x+y;
        break;
        case '-':result=x-y;
        break;
        case '*':result=x*y;
        break;
        case '/':if(y==0)
           {

           printf("divide by zero error\n");
           exit(0);
           }
           result=x/y;
           break;
    }
    printf("result=%f",result);
}
