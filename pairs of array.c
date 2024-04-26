#include<stdio.h>
void read(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void pair(int a[],int n,int t)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==t)
            {
                printf("%d and %d are the pairs that match the sum \n",a[i],a[j]);
            }
        }
    }
}
void read(int[],int);
void pair(int[],int,int);
main()
{
    int n,a[15],t;
    printf("Enter the size of an array\n");
    scanf("%d",&n);
    printf("Enter the sum that to be matched \n");
    scanf("%d",&t);
    printf("Enter the array elements...\n");
    read(a,n);
    pair(a,n,t);
}

