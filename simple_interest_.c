#include<stdio.h>
float interest(float,float,float);
main()
{
    float P,T,R,y,i;
    for(i=1;i<=3;i++)
    {
       printf("Enter the P , T , R\n");
    scanf("%f %f %f",&P,&T,&R);
    y=interest(P,T,R);
    printf("interest of =%f\n",y);

    }

    }
    float interest(float P,float T,float R)
    {
        float y;
        y=(P*T*R)/100;
        return y;
    }
