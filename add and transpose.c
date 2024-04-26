#include<stdio.h>
void read(int a[10][10],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void add(int a[10][10],int b[10][10],int c1[10][10],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            c1[i][j]=a[i][j]+b[i][j];
        }
    }
}
void display(int c1[10][10],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",c1[i][j]);
        }
        printf("\n");
    }
}
void transpose(int c1[10][10],int c ,int r,int x[10][10])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
             x[j][i]=c1[i][j];
        }
    }
}
void display1(int x[10][10],int c,int r)
{
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[10][10],b[10][10],c1[10][10],r,c,x[10][10];
    printf("Enter the size of rows and columns\n");
    scanf("%d %d",&r,&c);
    printf("Enter the matrix 1 elements\n");
    read(a,r,c);
    printf("Enter the matrix 2 elements\n");
    read(b,r,c);
    add(a,b,c1,r,c);
    printf("By adding elements New matrix elements are..\n");
    display(c1,r,c);
    transpose(c1,c,r,x);
    printf("transpose of matrix is..\n");
    display1(x,c,r);


}
