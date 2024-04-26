#include<stdio.h>
main()
{
    int i,n,a[20],temp,j;
    printf("Enter the nof array elements=\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("New array elements are...\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

}
