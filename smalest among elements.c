#include<stdio.h>
read(int[],int);
int minimum(int[],int);
display(int[],int);
int main()
{
    int num[30],n;
    printf("Enter the elements\n");
    scanf("%d",&n);
    read(num,n);
    display(num,n);
    minimum(num,n);
    return 0;

}
read(int num[],int n)
{  int i;
    for(i=0;i<n;i++){scanf("%d",&num[i]);}
}
display(int num[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",num[i]);
    }
}
int minimum(int num[],int n)
{
    int i,min=num[0];
    for(i=0;i<n;i++)
    {
        if(num[i+1]<num[i]){min=num[i+1];}
    }
    printf("minimum of elements=%d\n",min);

}
