
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

int  identity(int a[10][10],int m,int n)
{  int flag=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j && a[i][j]!=1)
            {
                flag=-1;
                break;
            }
            else if(i!=j && a[i][j]!=0)
            {
                flag=-1;
                break;
            }
        }
    }
    return flag;
}
main()
{
    int a[10][10],m,n,res;
    printf("Enter the row size and column size\n");
    scanf("%d %d",&m,&n);

    printf("Enter the matrix elements \n");
    read(a,m,n);
    display(a,m,n);
    res=identity(a,m,n);
    if(res==0)
    {
        printf("It is a identity matrix\n");
    }
    else printf("it is not a identity matrix\n");


}
