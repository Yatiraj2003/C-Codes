#include<stdio.h>
void read(int a[10][10],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }

    }
}

void display(int a[10][10],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}


void multiply(int a[10][10],int b[10][10],int c[10][10],int p,int q,int m,int n)
{
    int sum=0,i,j,k;

    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            sum=0;
            for(k=0;k<p;k++)
            {
                sum=sum+a[i][k]*b[k][j];
                c[i][j]=sum;
            }

    }
    }

}

main()
{
    int a[10][10],b[10][10],c[10][10],m,n,p,q;
    printf("Enter the row size of 1 matrix and row 2 and coulnm 1 and coulnm 2\n");
    scanf("%d %d %d %d",&m,&p,&n,&q);
    if(n==p)
    {
    printf("Enter the matrix elements 1\n");
    read(a,m,n);
    printf("Enter the matrix elements 2\n");
    read(b,p,q);
    display(a,m,n);
    display(b,p,q);
    multiply(a,b,c,p,q,m,n);
    printf("new elements are...\n");
    display(c,m,q);
    }
    else printf("rows and columns not same\n");

}


