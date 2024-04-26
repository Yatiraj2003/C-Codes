 #include<stdio.h>
main()
{
    int a,b,i,j,count=0,sum=0;
    printf("enter the range starting limit\n");
    scanf("%d",&a);
     printf("enter the range ending  limit");
    scanf("%d",&b);
 //   for(i=a;i<=b;i++)    /if u want to use loop add while(a<b) check your book/
   while(a<=b)
    { sum=0;
         for(j=1;j<a;j++)
    {

       if(a%j==0)
       {
           sum=sum+j;
       }


    }
    if(sum==a)
    {
        printf("%d its a perfect number\n",a);
        count++;
    }

    a++;

    }
     printf("number of perfect number = %d",count);
}

