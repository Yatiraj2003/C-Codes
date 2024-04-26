

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

void diasum(int a[10][10],int m,int n)
{  int sum=0;
    for(int i=0;i<m;i++)
    {  for(int j=0;j<n;j++)
    {
        if((i+j)==n-1)
        sum=sum+a[i][j];
    }}
         printf("sum of secondary  diagonal elements is %d\n",sum);

}

main()
{
    int a[10][10],m,n;
    printf("Enter the row size and column size\n");
    scanf("%d %d",&m,&n);

    printf("Enter the matrix elements 1\n");
    read(a,m,n);
    display(a,m,n);
    diasum(a,m,n);


}
