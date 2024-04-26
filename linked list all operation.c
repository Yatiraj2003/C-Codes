#include<stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
}*node;

  node insertend(node,node,node);
  node insertbeg(node,node);
  node deleteend(node,node,node,node);
  node deletebeg(node,node,node);
  node insertspecific(node,node,node,node);
  node deletespecific(node,node,node,node);
  int countnodes(node,node);
  void  display(node,node);
  void findduplicate(node,node);
  node deleteduplicate(node,node);

int main()
{

  node head=NULL,prev=NULL,net=NULL,cur=NULL,newnode,temp;

    int ch,count1;
    for(;;)
    {
    printf("Choose the appropriate option listed below\n");
    printf("1) Insert at end\n 2) insert to beginning\n 3) delete at end\n 4) delete from beginning\n 5) insert at specific position\n 6) display\n 7) number of nodes\n 8) delete at specific position\n  9) print the duplicate data\n 10) delete duplicate \n11) exit \n");
    scanf("%d",&ch);
    switch(ch)
    {
         case 1: head=insertend(newnode,head,temp);
         break;
         case 2: head=insertbeg(newnode,head);
         break;
         case 3: head=deleteend(newnode,head,temp,prev);
         break;
         case 4: head=deletebeg(newnode,head,temp);
         break;
         case 5: head=insertspecific(newnode,temp,prev,head);
         break;
         case 6: display(head,temp);
         break;
         case 7: count1=countnodes(temp,head);
                  printf("Number of nodes are %d\n",count1);
         break;
         case 8: head=deletespecific(newnode,head,prev,cur);
         break;
         case 9: findduplicate(newnode,head);
         break;
         case 10: head=deleteduplicate(newnode,head);
         break;

         case 11: exit(0); break;

         default: printf("Invalid input\n");
    }
    }

}

node getnode(node newnode)
{
    newnode=(node) malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory is not allocated\n");
    }
    else
    {
        return newnode;
    }
}

node readdetails(node newnode)
{
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}

node insertend(node newnode,node head,node temp)
{
    newnode=getnode(newnode);
    newnode=readdetails(newnode);
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
            temp->next=newnode;
        return head;
    }

}

node insertbeg(node newnode,node head)

{
    newnode=getnode(newnode);
    newnode=readdetails(newnode);
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
}

void display(node head,node temp)
{
    if(head==NULL)
    {
        printf("LIST is empty\n");
        exit(0);
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }

    }
}

node deleteend(node newnode,node head,node temp,node prev)
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
       if(head->next==NULL)
       {
           printf("deleted=%d\n",head->data);
           free(head);
           head=NULL;
           return head;
       }

       else
       {
          temp=head;
          while(temp->next!=NULL)
          {
              prev=temp;
              temp=temp->next;
          }
          prev->next=NULL;
           printf("Deleted=%d\n",temp->data);
          free(temp);
          return head;
       }
    }

}

   node deletebeg(node newnode,node head,node temp)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    else
    {
        if(head->next==NULL)
        {

       printf("deleted=%d\n",head->data);
       free(head);
       head=NULL;
       return head;
         }

    else
    {
       temp=head;
    head=temp->next;
    printf("Deleted=%d\n",temp->data);
    free(temp);
    return head;

    }
    }
}

node insertspecific(node newnode,node temp,node prev,node head)
{
    int pos,p;
    printf("Enter the position before which node is to be added\n ");
    scanf("%d",&pos);
    newnode=getnode(newnode);
    newnode=readdetails(newnode);

    if(pos==1)
    {
       head=insertbeg(newnode,head);
    }
    else
    {
        p=1;
        temp=head;
        while(p!=pos)
        {
           prev=temp;
           temp=temp->next;
           p++;
        }
         prev->next=newnode;
         newnode->next=temp;
    }
    return head;
}

int countnodes(node temp,node head)
{
    int count=0;
    if(head==NULL)
    {
        count=0;
    }

    else
        {
            temp=head;
            while(temp!=NULL)
            {
                count++;
                temp=temp->next;
            }


        }
        return count;

}

node deletespecific(node newnode,node head,node prev,node cur)
{
    int pos,p;
    printf("Enter the position  is to be deleted\n ");
    scanf("%d",&pos);
    if(pos==1)
    {
        free(head);
        head=NULL;
        return head;
    }

    else
        {
            p=1;
           cur=head;
            while(cur->next!=NULL && p!=pos)
            {
                prev=cur;
                cur=cur->next;
                p++;
            }
            prev->next=cur->next;
            printf("Deleted is %d\n",cur->data);
            free(cur);
            return head;
        }

}

void findduplicate(node newnode,node head)
{
    if(head==NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        node ptr;
        while(head->next!=NULL)
        {
            ptr=head->next;
            while(ptr!=NULL)
            {
            if(head->data==ptr->data)
            {
                printf("%d\n",ptr->data);
                break;
            }
            ptr=ptr->next;
        }
        head=head->next;

    }
}
}

node deleteduplicate(node newnode,node head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        node ptr1,ptr2,dup;
        ptr1=head;
        while(ptr1->next!=NULL)
        {
            ptr2=ptr1;
            while(ptr2->next!=NULL)
            {
                if(ptr1->data==ptr2->next->data)
                {
                   dup=ptr2->next;
                   ptr2->next=ptr2->next->next;
                   free(dup);
                }
                else
                {
                    ptr2=ptr2->next;
                }

            }
            ptr1=ptr1->next;
        }
        return head;
    }
}

