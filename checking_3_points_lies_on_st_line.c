#include<stdio.h>
main()
{
    float x1,x2,y1,y2,x3,y3;
    int m,n;
    printf("Enter the values for x1,x2,x3,y1,y2,y3\n");
    scanf("%f%f%f%f%f%f",&x1,&x2,&x3,&y1,&y2,&y3);
    m= (y2-y1)/(x2-x1);
    n= (y3-y2)/(x3-x2);
    if(m==n)
    {
        printf("three points are lies on same line\n");
    }
    else
    {
        printf("not lies on same line\n");
    }

}
