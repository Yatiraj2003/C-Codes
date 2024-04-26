/*to calculate total payment of employees*/
#include<stdio.h>
main()
{
    int days,hr,amount;
    printf("enter the no of days and hrs worked\n");
    scanf("%d%d",&days,&hr);

    switch(days)

   {
        case 1 ... 3:
        amount=(250*hr)+(100*days);
        printf("amount=%d",amount);
        break;
        case 4 ... 6:
        amount=(250*hr)+(100*days);
        printf("amount=%d",amount);
        break;
        case 7 ... 9:

        amount=(250*hr)+(100*days);
        printf("amount=%d",amount);
        break;
   }

}
