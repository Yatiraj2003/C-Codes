/*simple calculator*/
#include<stdio.h>
main()
{
    int x,y,result;
    char op;
    printf("enter two numbers\n");
    scanf("%d%d",&x,&y);
    printf("choose operator +,-,*,/\n ");
    scanf(" %c",&op);
    if(op=='+')
    {
        result=x+y;
        printf("addition of %d and %d=%d",x,y,result);
    }

    else if(op=='-')
    {
        result=x-y;
        printf("substraction of %d and %d=%d",x,y,result);
    }
    else if(op=='*')
    {
        result=x*y;
        printf("multiplication of %d and %d =%d",x,y,result);
    }
    else
    {
        result=x/y;
        printf("division of %d and %d =%d",x,y,result);
    }







}
