#include<stdio.h>
void read(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void duplicate(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
 for(int j=i+1;j<n;j++)
 {
     if(a[i]==a[j])
        printf(" duplicate numbers are %d\n",a[j]);
 }
    }
}

void read(int[],int);
void dupliacte(int[],int);
main()
{
    int n,a[15];
    printf("Enter the size of an array\n");
    scanf("%d",&n);
    read(a,n);
    duplicate(a,n);
}

