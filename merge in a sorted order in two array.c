#include<stdio.h>
void read(int a[],int n)
{  int temp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int j=0;j<n;j++)
    {
        for(int k=j+1;k<n;k++)
        {
            if(a[j]>a[k])
            {
                temp=a[j];
                a[j]=a[k];
                a[k]=temp;
            }
        }
    }
}

void read1(int b[],int m)
{  int temp;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int j=0;j<m;j++)
    {
        for(int k=j+1;k<m;k++)
        {
            if(b[j]>b[k])
            {
                temp=b[j];
                b[j]=b[k];
                b[k]=temp;
            }
        }
    }
}
void merge(int a[],int b[],int c[],int n ,int m)
{  int temp;
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
    for(int x=0;x<n+m;x++)
    {
        for(int y=x+1;y<n+m;y++)
        {
            if(c[x]>c[y])
            {
                temp=c[x];
                c[x]=c[y];
                c[y]=temp;
            }
        }
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


