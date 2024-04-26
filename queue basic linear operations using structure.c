#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue
{
    int data[100];
    int front;
    int rear;
}k;

void Enqueue(struct Queue *q,char);
char Dequeue(struct Queue *q);
void show(struct Queue *q);

int main()
{
    k sk;
    char item;
    k *q;
    q=&sk;
    q->front=-1;
    q->rear=-1;
    int op,x;
    while(1)
    {
        printf("Choose your option\n");
        printf(" 1: Insertion \n 2: Deletion\n 3: Display\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("Enter the element\n");
            scanf(" %c",&item);
            Enqueue(q,item);
            break;
            case 2: x=Dequeue(q);
            printf("%d is the deleted element\n",x);
            break;
            case 3: show(q);
            break;
            default : exit(0);
            break;
        }
    }
}

void Enqueue(k *q,char item)
{
    if(q->rear==100-1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(q->front==-1)
        {
            q->front=0;
        }
        q->rear++;
        q->data[q->rear]=item;
    }
}
char Dequeue(k *q)
{
    char ele;
    if(q->front==-1 || q->front>q->rear)
    {
        printf("Queue underflow\n");
        exit(1);
    }
    else
    {
        ele=q->data[q->front];
        q->front++;
        return ele;
    }
}

void show(k *q)
{
    if(q->front==-1 || q->front >q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=q->front;i<=q->rear;i++)
        {
            printf("%c ",q->data[i]);
        }
    }
}
