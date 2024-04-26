#include<stdio.h>
void read(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void leader(int a[],int n)
{    int l;
    for(int i=0;i<n;i++)
    {   l=1;
        for(int j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
               {l=0;
                break;}
        }
        if(l==1)
        {
            printf("%d is the leader element\n",a[i]);
        }
}
}


void read(int[],int);
void leader(int[],int);
main()
{
    int a[15],n;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    printf("Enter the array elements...\n");
    read(a,n);
    leader(a,n);
}

