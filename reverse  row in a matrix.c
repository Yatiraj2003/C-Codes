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

void display(int a[10][10],int r,int c)
{
    for(int i=0;i<r;i++)
    {
       for( int j=0;j<c;j++)
       {
           printf("%d ",a[i][j]);
       }
       printf("\n");
    }
}

void reverse1(int a[10][10],int r,int c)
{
    int i,b[100];
    for( i=0;i<r;i++)
  {

      int j,temp;
    for(j=0;j<(c/2);j++)
    {
        temp=a[j];
        a[j]=a[c-i-1];
        a[c-i-1]=temp;
    }
   }
   for(int i=0;i<r;i++)
    {
       for( int j=0;j<c;j++)
       {
           printf("%d ",a[i][j]);
       }
       printf("\n");
    }
  }



int main()
{
    int a[10][10],r,c;

    printf("Enter the row and column size\n");
    scanf("%d %d",&r,&c);
    printf("Enter the matrix elements\n");
    read(a,r,c);
    display(a,r,c);
    reverse1(a,r,c);

}
