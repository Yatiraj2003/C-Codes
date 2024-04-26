
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
  node head=NULL,p=NULL,net=NULL,cur=NULL,t1=NULL,last=NULL;

  node insertend(node);
  node insertbeg(node);
  node deleteend(node);
  node deletebeg(node);
  node insertspecific(node);
  node deletespecific(node);
  int countnodes(node);
  void  displayfront(node);
  void  displaybackward(node);
int main()
{
    int ch,count1;
    for(;;)
    {
    printf("Choose the appropriate option listed below\n");
    printf("1) Insert at end\n 2) insert to beginning\n 3) delete at end\n 4) delete from beginning\n 5) insert at specific position\n 6) display forward\n 7) number of nodes\n 8) delete at specific position\n 9) Display backward\n 10) exit \n");
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
         case 8: head=deletespecific(head);
         break;

         case 9:displaybackward(head);
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
    newnode->prev=newnode;
    newnode->next=newnode;
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
        last=head->prev;
        last->next=newnode;
        newnode->next=head;
        newnode->prev=last;
        head->prev=newnode;
        return head;

    }

}

node insertbeg(node head)

{
    newnode=getnode();
    newnode=readdetails(newnode);
    if(head==NULL)
    {

        return newnode;
    }
    else
    {
        last=head->prev;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        last->next=head;
        head->prev=last;
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
        while(temp->next!=head)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);

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
        last=temp->prev;
        while(temp->next!=head)
        {
            printf("%d\n",last->data);
            last=last->prev;
        }
        printf("%d\n",last->data);

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
       if(head->next==head)
       {
           printf("deleted=%d\n",head->data);
           free(head);
           head=NULL;
           return head;
       }

       else
       {
          temp=head;
          while(temp->next!=head)
          {
              temp=temp->next;
          }
          temp->prev->next=head;
          head->prev=temp->prev;

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
        if(head->next==head && head->prev==head)
        {

       printf("deleted=%d\n",head->data);
       free(head);
       head=NULL;
       return head;
         }

    else
    {
       temp=head;
       last=head->prev;
       net=temp->next;
       net->prev=last;
       last->next=net;
       head=net;
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
        last=head->prev;
        newnode->next=head;
        last->next=newnode;
        head->prev=newnode;
        newnode->prev=last;
        head=newnode;
    }

    else
    {

        temp=head;
        while(p!=pos && temp->next!=head)
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
          newnode->next=head;
          head->prev=newnode;
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
            last=temp->prev;
            while(temp!=head)
            {
                count++;
                temp=temp->next;
            }


        }
        return (count+1);

}

node deletespecific(node head)
{
    int pos,p=1;
    printf("Enter the position  is to be deleted\n ");
    scanf("%d",&pos);
    if( head==NULL)
    {
        printf("List is empty\n");
    }
    if(pos==1)
    {
        temp=head;
        last=head->prev;
        net=head->next;
        last->next=net;
        net->prev=last;
        head=net;
        printf("Deleted = %d\n",temp->data);
        free(temp);

    }
    else{
            p=1;
        temp=head;
        last=head->prev;
        while(temp->next!=head && p!=pos)
        {
            net=temp;
            temp=temp->next;
            t1=temp->next;
            p++;
        }
        if(pos==p)
        {
            net->next=t1;
            t1->prev=net;
            printf("Deleted = %d\n",temp->data);
            free(temp);
        }
        else if(temp==last && p==pos)
        {
            net->next=head;
            head->prev=net;
            printf("Deleted =%d\n",temp->data);
            free(temp);

        }
    }
    return head;


}
