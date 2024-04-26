#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Music
{
    char song_name[100];
    char singer_name[50];
    char movie_name[50];
    int song_size;
    struct Music *next;
    struct Music *prev;

};

typedef struct Music *node;
node newnode,temp=NULL,head=NULL,cur=NULL,pre=NULL,net=NULL;

node insertend(node);
void displayforward(node);
node insert_after_a_node(node);
node deletespecific(node);


int main()
{
    int ch;
    for(;;)
    {
        printf("Choose the below option -----------------\n");
        printf(" 1-- Insert at end \n 2-- display from forward direction \n 3-- Insert after a particular song\n 4-- Delete a specific song\n 5-- exit from loop\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insertend(head);
            break;
            case 2: displayforward(head);
            break;
            case 3: head=insert_after_a_node(head);
            break;
            case 4: head=deletespecific(head);
            break;
            case 5: exit(0);
            break;
            default : printf("Invalid option entered by user!!!!!!\n");
            break;
        }

    }
}

node getnode()
{
    newnode=(node)malloc(sizeof(struct Music));
    if(newnode==NULL)
    {
        printf("Memory is not allocated------------\n");

    }
    else
    {
        return newnode;
    }
}
node read(node newnode)
{
    printf("Enter the song name--------\n");
    scanf("%s",newnode->song_name);
    printf("Enter the singer name-------\n");
    scanf("%s",newnode->singer_name);
    printf("Enter the movie name--------\n");
    scanf("%s",newnode->movie_name);
    printf("Enter the size of the song in kb's----\n");
    scanf("%d",&newnode->song_size);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

node insertend(node head)
{
    newnode=getnode();
    newnode=read(newnode);
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

void displayforward(node head)
{
    if(head==NULL)
    {
        printf("LIST is empty--------------------\n");
        exit(0);
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
           printf(" the name of song  is ----%s \n",temp->song_name);
           printf(" the Singer name is---- %s\n",temp->singer_name);
           printf(" the movie name of  song is---- is %s\n",temp->movie_name);
           printf("the song size is--- %d\n",temp->song_size);
            temp=temp->next;
        }

    }

}

node insert_after_a_node(node head)
{
    char song[100];
    printf("Enter the song name after that song new song to be inserted\n ");
    scanf("%s",song);
    newnode=getnode();
    newnode=read(newnode);
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    if(head->next==NULL && head->prev==NULL && strcmp(head->song_name,song)==0 )
    {
        head->next=newnode;
        newnode->prev=head;
        return head;
    }
    temp=head;
    while(temp->next!=NULL)
    {

        if(strcmp(temp->song_name,song)==0)
        {
           temp->next=newnode;
           newnode->prev=temp;
           newnode->next=net;
           net->prev=newnode;
           return head;

        }
        temp=temp->next;
        net=temp->next;
    }
     if(strcmp(temp->song_name,song)==0)
     {

        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
        return head;

    }
}

node deletespecific(node head)
{
    char song[100];
    printf("Enter the song name after that song new song to be inserted\n ");
    scanf("%s",song);
    if(head==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    if(head->next==NULL && head->prev==NULL && strcmp(head->song_name,song)==0 )
    {
        printf("Deleted song is -- %s---------\n",head->song_name);
        free(head);
        head=NULL;
        return head;
    }
    temp=head;
    while(temp->next!=NULL)
    {

        if(strcmp(temp->song_name,song)==0)
        {
           pre->next=net;
           net->prev=pre;
           printf("Deleted song is -- %s-------\n",temp->song_name);
           free(temp);
           return head;

        }
        pre=temp;
        temp=temp->next;
        net=temp->next;
    }
    if(strcmp(temp->song_name,song)==0)
    {
        pre->next=NULL;
        printf("Deleted song is %s---\n",temp->song_name);
        free(temp);
        return head;
    }
}






