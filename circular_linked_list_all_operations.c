#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *node;
node newnode,head=NULL,prev=NULL,cur=NULL,temp=NULL;


node insertend(node);
node insertfront(node);
node deleteend(node);
node deletefront(node);
node insertspecific(node);
node deletespecific(node);
void display(node);


int main()
{
    int op;
    for(;;)
    {
        printf("choose the option\n");
        printf("1) insert at the end\n 2) insert at front\n 3) delete at end\n 4) delete at front\n 5) insert at specific position\n 6) delete at specific position\n 7) display the data \n 8) exit the program\n ");
        scanf("%d",&op);
        switch(op)
        {
            case 1: head=insertend(head);
            break;
            case 2: head=insertfront(head);
            break;
            case 3: head=deleteend(head);
            break;
            case 4: head=deletefront(head);
            break;
            case 5: head=insertspecific(head);
            break;
            case 6: head=deletespecific(head);
            break;
            case 7: display(head);
            break;
            case 8: exit(0);
            break;
            default :
                printf("Entered invalid input\n");
                break;

        }
    }
}

node getnode()
{
    newnode=(node)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory is not allocated\n");
    }
    else
    {
        return newnode;
    }
}

node read(node newnode)
{
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=newnode;
    return newnode;
}

node insertend(node head)
{
    newnode=getnode();
    newnode=read(newnode);
    if(head==NULL)
    {
        return newnode;
    }
    cur=head;
    while(cur->next!=head)
    {
        cur=cur->next;
    }
    cur->next=newnode;
    newnode->next=head;
    return  head;
}

node insertfront(node head)
{
    newnode=getnode();
    newnode=read(newnode);
    if(head==NULL)
    {
        return newnode;
    }
    cur=head;
    while(cur->next!=head)
    {
        cur=cur->next;
    }
    newnode->next=head;
    cur->next=newnode;
    head=newnode;
    return head;

}

node deleteend(node head)
{
    if(head==NULL)
    {
        printf("Cannot delete\n");
    }
    else
    {
        if(head->next==head)
        {
            printf("Deleted =%d\n",head->data);
            free(head);
            head=NULL;
            return head;
        }

        else
        {
            cur=head;
            while(cur->next!=head)
            {
                prev=cur;
                cur=cur->next;
            }
            prev->next=head;
            printf("Deleted =%d\n",cur->data);
            free(cur);
            return head;
        }
    }
}

node deletefront(node head)
{
    if(head==NULL)
    {
        printf("cannot delete\n");
    }
    else
    {
    if(head->next==head)
        {
            printf("Deleted =%d\n",head->data);
            free(head);
            head=NULL;
            return head;
        }
        else
        {
            cur=head;
            while(cur->next!=head)
            {
                cur=cur->next;
            }
            temp=head;
            cur->next=temp->next;
            head=temp->next;
            printf("Deleted =%d\n",temp->data);
            free(temp);
            return head;

        }

}

}

void display(node head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        cur=head;
        while(cur->next!=head)
        {
            printf("%d\n",cur->data);
            cur=cur->next;
        }
        printf("%d\n",cur->data);
    }
}

node insertspecific(node head)
{
    newnode=getnode();
    newnode=read(newnode);
    int pos,count=1;
    printf("Enter the position to be insert\n");
    scanf("%d",&pos);
    if(head==NULL)
    {
        return newnode;
    }
    if(pos==1)
    {
        cur=head;
        while(cur->next!=head)
        {
            cur=cur->next;
        }
        cur->next=newnode;
        newnode->next=cur;
        return head;
    }
    cur=head;
    while(cur->next!=head && count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }

    if(count==pos)
    {
        newnode->next=cur;
        prev->next=newnode;
        return head;
    }

    if(count+1==pos)
    {
       cur->next=newnode;
       newnode->next=head;
       return head;
    }
    else
    {
        printf("Invalid position\n");
        return 0;
    }


}

node  deletespecific(node head)
{
    int pos,count=1;
    printf("Enter the position to be deleted\n");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("List is empty\n");
    }
     if(pos==1)
        {
            cur=head;
            while(cur->next!=head)
            {
                cur=cur->next;
            }
            temp=head;
            cur->next=temp->next;
            head=temp->next;
            printf("Deleted =%d\n",temp->data);
            free(temp);
            return head;

        }

            cur=head;
            while(cur->next!=head && count!=pos)
            {
                prev=cur;
                cur=cur->next;
                count++;
            }
            if(count==pos)
            {
                prev->next=cur->next;
                printf("Deleted=%d\n",cur->data);
                free(cur);
                return head;
            }

        else
        {
             printf("invalid position\n");
        }

}


