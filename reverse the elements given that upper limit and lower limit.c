#include<stdio.h>
void read(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void reverse(int a[],int n,int l,int u)
{  int i,j,temp;
  i=l;
  j=u;
   while(i<j)

    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }

}
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void read(int [],int);
void reverse(int [],int,int,int);
void display(int[],int);
int main()
{
    int n,a[100],l,u;
    printf("Enter the number of elemets\n");
    scanf("%d",&n);
    printf("Enter the lower limit and upper limit\n");
    scanf("%d %d",&l,&u);
    printf("Enter the array elements..\n");
    read(a,n);
    reverse(a,n,l,u);
    display(a,n);
    return 0;

}

