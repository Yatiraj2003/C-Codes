#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int s;
    int f,r;
    int Q[6];
};

void create(struct Queue *q,int s)
{
    q->s=s;
    q->f=q->r=0;
}

void enqueue(struct Queue *q,int x)
{
    if(q->r==q->s-1)
    {
        printf("queue is full\n");
    }
    else
    {
        q->r++;
        q->Q[q->r]=x;
    }
}
int dequeue(struct Queue *q)
{
    int x;
    if(q->f==q->r)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->f++;
        x=q->Q[q->f];
    }
    return x;
}

int isEmpty(struct Queue *q)
{
    return q->f==q->r;
}

int main()
{
    char h,k,l;
    int u,v,i,j,a[6][6]={0};
    FILE *fp=fopen("graph_Inputfile.txt","r");
    while(!feof(fp))
    {
        fscanf(fp," %c %c %c",&h,&k,&l);
        //printf("%c %c %c\n",h,k,l);
        u=h-'A';
        v=l-'A';
        a[u][v]=1;
    }
    fclose(fp);
   /* for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/
    BFS(a,1);
    return 0;
}

void BFS(int a[6][6],int i)
{
    int u,v,k,j;
    int visited[6]={0};
    struct Queue *q;
    create(q,6);
    printf("%d ",i);
    visited[i]=1;
    enqueue(q,i);
    while(!isEmpty(q))
    {
        u=dequeue(q);
        for(v=1;v<6;v++)
        {
            if(a[u][v]==1 && visited[v]==0)
            {
                printf("%d ",v);
                visited[v]=1;
                enqueue(q,v);
            }
        }
    }
}


