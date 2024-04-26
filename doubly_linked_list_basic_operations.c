
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node *node;
  node head,newnode,temp,p,t1;
  node head=NULL,p=NULL,net=NULL,cur=NULL,t1=NULL;

  node insertend(node);
  node insertbeg(node);
  node deleteend(node);
  node deletebeg(node);
  node insertspecific(node);
  node deletepos(node);
  int countnodes(node);
  void  displayfront(node);
  void  displaybackward(node);
int main()
{
    int ch,count1;
    for(;;)
    {
    printf("Choose the appropriate option listed below\n");
    printf("1) Insert at end\n 2) insert to beginning\n 3) delete at end\n 4) delete from beginning\n 5) insert at specific position\n 6) display forward\n 7) number of nodes\n  8) Display backward\n 9) Delete at specific position\n 10) exit \n");
    scanf("%d",&ch);
    switch(ch)
    {
         case 1: head=insertend(head);
         break;
         case 2: head=insertbeg(head);
         break;
         case 3: head=deleteend(head);
         break;
         case 4: head=deletebeg(head);
         break;
         case 5: head=insertspecific(head);
         break;
         case 6: displayfront(head);
         break;
         case 7: count1=countnodes(head);
            printf("Number of nodes are %d\n",count1);
         break;
         case 8:displaybackward(head);
         break;
          case 9: head=deletepos(head);
          break;
          case 10: exit(0);
          break;

         default: printf("Invalid input\n");
    }
    }

}

node getnode()
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
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

node insertend(node head)
{
    newnode=getnode();
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
            newnode->prev=temp;
        return head;

    }

}

node insertbeg(node head)

{
    newnode=getnode();
    newnode=readdetails(newnode);
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return head;
    }
}

void displayfront(node head)
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


void displaybackward(node head)
{
    if(head==NULL)
    {
        printf("LIST is empty\n");
        exit(0);
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        net=temp;
        while(net!=NULL)
        {
            printf("%d\n",net->data);
            net=net->prev;
        }

    }
}

node deleteend(node head)
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
              net=temp;
              temp=temp->next;
          }
          net->next=NULL;
           printf("Deleted=%d\n",temp->data);
          free(temp);
          return head;
       }
    }

}

   node deletebeg(node head)
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
    head->prev=NULL;
    printf("Deleted=%d\n",temp->data);
    free(temp);
    return head;


    }
    }
}

node insertspecific(node head)
{
    int pos,p=1;
    newnode=getnode();
    newnode=readdetails(newnode);
    printf("Enter the position before which node is to be added\n ");
    scanf("%d",&pos);
    if(pos>1 && head==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }

    if(pos==1)
    {
       head=insertbeg(head);
    }

    else
    {

        temp=head;
        while(p!=pos && temp->next!=NULL)
        {
           net=temp;
           temp=temp->next;
           p++;
        }
     if(pos>p+1)
    {
    printf("Invalid input\n");
      }
      if(pos==p)
      {
          net->next=newnode;
          newnode->prev=net;
          newnode->next=temp;
          temp->prev=newnode;
      }
      if(pos==p+1)
      {
          temp->next=newnode;
          newnode->prev=temp;
      }



    }
    return head;
}

int countnodes(node head)
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

node deletepos(node head)
{
    int pos,p=1;
    printf("Enter the position \n");
    scanf("%d",&pos);
    if(pos==1)
    {
        temp=head;
        printf("Deleted = %d\n",temp->data);
        head=temp->next;
        head->prev=NULL;
        free(temp);
    }
    else if(head->next==NULL)
    {
        printf("Deleted = %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
       temp=head;
        while(p!=pos && temp->next!=NULL )
        {
            net=temp;
            temp=temp->next;
            p++;
        }
        if(p==pos&& temp->next==NULL)
        {
            net->next=NULL;
            printf("Deleted =%d\n",temp->data);
            free(temp);
        }
        else if(p==pos)
        {
            net->next=temp->next;
            temp->next->prev=net;
            printf("Deleted = %d\n",temp->data);
            free(temp);
        }
        else
        {
            printf("Invalid position\n");
            exit(1);
        }
    }
    return head;

}




