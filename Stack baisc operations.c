#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 100

struct stack
{
    int data[SIZE];
    int top;
};

int main()
{
    struct stack p,*sp;
    sp=&p;
    int top;
    int op,item;
    sp->top=-1;
    while(1)
    {
        printf("Enter the option\n");
        printf(" 1: push\n 2:pop\n 3: toppest element\n 4: exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter the data\n");
                scanf("%d",&item);
                push(sp,item);
                break;
            case 2:
                pop(sp);
                 break;
            case 3:  printf("%d\n",sp->data[sp->top]);
                break;
            case 4: display(sp);
                break;
        }
    }
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
void display(struct stack *sp)
{
    int temp;
    if(sp->top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        temp=sp->top;
        while(sp->top!=-1)
        {
            printf("%d\n",sp->data[sp->top]);
            sp->top--;
        }
        sp->top=temp;
    }
}
