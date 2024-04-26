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
int identical(int a[10][10],int b[10][10],int m,int n)
{  int flag=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==b[i][j])
            {
                flag=1;
                break;
            }
        }
    }
    return flag;
}

main()
{
    int a[10][10],b[10][10],m,n,k,l,res;
    printf("Enter the row 1 and coulmn 1 and row 2 and column 2 size \n");
    scanf("%d %d %d %d",&m,&n,&k,&l);
    if(m==k && n==l)
        {
            printf("Enter the matrix 1 elements\n");
            read(a,m,n);
            display(a,m,n);
            printf("Enter the matrix 2 elements\n");
            read(b,k,l);
            display(b,k,l);
            res=identical(a,b,m,n);
            if(res==1)
            {
                printf("a and b matrix are identical\n");
            }
            else
            {
                printf("not identical\n");
            }
        }
        else
        {
            printf("rows and coulmns of 2 matrix is not equal\n");
        }


}

