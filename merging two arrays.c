#include<stdio.h>
void read(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void read1(int b[],int m)
{
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
}
void merge(int a[],int b[],int c[],int n ,int m)
{
    int k=0;
    for(int i=0;i<n;i++)
    {
        c[k]=a[i];
        k++;
    }
    for(int j=0;j<m;j++)
    {
        c[k]=b[j];
        k++;
    }
}
void display(int c[],int n,int m)
{
    for(int i=0;i<(n+m);i++)
    {
        printf("%d ",c[i]);
    }
}
void read(int[],int);
void read1(int[],int);
void merge(int[],int[],int[],int,int);
void display(int[],int,int);
main()
{
    int n,a[15],m,b[15],c[30];
    printf("Enter the size of an array 1\n");
    scanf("%d",&n);
    printf("Enter the size of array 2\n ");
    scanf("%d",&m);
    printf("Enter the array a elements..\n");
    read(a,n);
    printf("Enter the array b elements..\n");
    read1(b,m);
    merge(a,b,c,n,m);
    display(c,n,m);
}

