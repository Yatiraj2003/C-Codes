#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
struct stack
{
    int data[SIZE];
    int top;
};

int isEmpty(struct stack *sp)
{
    if(sp->top==-1)
    {
        return 1;
    }
    return 0;
}

 struct stack k,*sp;

    sp->top=-1;
void DFS(int a[10][10],int u)
{
    int i,j,v,visited[10]={0};
    printf("%d ",u);
    push(sp,u);
    visited[u]=1;
    while(!isEmpty(sp))
    {
        for(v=1;v<10;v++)
        {
            if(a[u][v]==1 && visited[v]==0)
            {
                DFS(a,v);
            }
        }
    }
}
int main()
{
    FILE *fp=fopen("graph_Inputfile.txt","r");
   int i,j,a[10][10]={0};
   int u,v;
   char h,k,l;
   while(!feof(fp))
   {
       fscanf(fp,"%c %c %c",&h,&k,&l);
       u=h-'A';
       v=l-'A';
       a[u][v]=1;
   }
   fclose(fp);
  printf("DFS of graph is---\n");
    DFS(a,1);
}

void push(struct stack *sp,int item)
{
    if(sp->top==SIZE-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        sp->top++;
        sp->data[sp->top]=item;
    }
}

void pop(struct stack *sp)
{
    int item;
    if(sp->top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        item=sp->data[sp->top];
        sp->top--;
        printf("%d\n",item);
    }

}

