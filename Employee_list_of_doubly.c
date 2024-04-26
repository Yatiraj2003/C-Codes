
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee
{
    char name[50];
    char company_name[50];
    int age;
    int salary;
    char designation[50];
    int emp_id;
    struct Node *next;
    struct Node *prev;
};

typedef struct Employee *node;
  node head,newnode,temp,p,t1;
  node head=NULL,p=NULL,net=NULL,cur=NULL,t1=NULL;

  node insertend(node);
  node insertbeg(node);
  int countdesignation(node);
  void  displayfront(node);
  void  displaybackward(node);
  node delete_empid(node);
  void search_comp_name(node);
  void display_designation(node);

int main()
{
    int ch,count1;
    for(;;)
    {
    printf("Choose the appropriate option listed below\n");
    printf("1) Insert at end\n 2) insert to beginning\n 3) delete based on employee id\n 4)search based on company name \n 5) display based on designation\n 6) display forward\n 7) count based on designation\n 8)Display backward\n  9) exit \n");
    scanf("%d",&ch);
    switch(ch)
    {
         case 1: head=insertend(head);
         break;
         case 2: head=insertbeg(head);
         break;
         case 3: head=delete_empid(head);
         break;
         case 4: search_comp_name(head);
         break;
         case 5: display_designation(head);
         break;
         case 6: displayfront(head);
         break;
         case 7: count1=countdesignation(head);
                  printf("Number of nodes of particular designation  are %d\n",count1);
         break;

         case 8:displaybackward(head);
          break;
          case 9: exit(0);
          break;


         default: printf("Invalid input\n");
    }
    }

}

node getnode()
{
    newnode=(node) malloc(sizeof(struct Employee));
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
    printf("Enter the name of employee\n");
    scanf("%s",newnode->name);
    printf("Enter the age of employee\n");
    scanf("%d",&newnode->age);
    printf("Enter the company name of employee\n");
    scanf("%s",newnode->company_name);
    printf("Enter the salary of employee\n");
    scanf("%d",&newnode->salary);
    printf("Enter the designation of employee\n");
    scanf("%s",newnode->designation);
    printf("Enter the employeeID\n ");
    scanf("%d",&newnode->emp_id);

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
           printf(" the name of employee is %s \n",temp->name);
    printf(" the age of employee is %d\n",temp->age);
    printf(" the company name of employee is %s\n",temp->company_name);
    printf("the salary of employee is %d\n",temp->salary);
    printf(" the designation of employee is %s\n",temp->designation);
    printf("the employeeID is %d\n ",temp->emp_id);
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
             printf(" the name of employee is %s \n",net->name);
    printf(" the age of employee is %d\n",net->age);
    printf(" the company name of employee is %s\n",net->company_name);
    printf("the salary of employee is %d\n",net->salary);
    printf(" the designation of employee is %s\n",net->designation);
    printf("the employeeID is %d\n ",net->emp_id);
            net=net->prev;
        }

    }
}

node delete_empid(node head)
{
    int id;
    printf("Enter the employee id to be deleted\n");
    scanf("%d",&id);
    if(head==NULL)
    {
       printf("List is empty\n");
       exit(0);
    }
    if(head->emp_id==id)
    {
        temp=head;
    head=temp->next;
    head->prev=NULL;
    printf("Deleted= %s\n",temp->name);
    free(temp);
    return head;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        net=temp;
        temp=temp->next;
        t1=temp->next;
        if(temp->emp_id==id)
        {
            net->next=t1;
            t1->prev=net;
            printf("Deleted= %s\n",temp->name);
            free(temp);
            return head;
        }

    }
    if(temp->emp_id==id)
        {
            net->next=NULL;
            printf("Deleted= %s\n",temp->name);
            free(temp);
            return head;
        }


}

void search_comp_name(node head)
{
    char compname[50];
    printf("Enter the company name to be checked\n");
    scanf("%s",compname);
    if(head==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    if(head->next==NULL)
    {
        if(strcmp(head->company_name,compname)==0)
        {
            printf("%s",head->company_name);
            printf("It is found\n");

        }
    }
    else{
    cur=head;
    while(cur!=NULL)
    {
        if(strcmp(cur->company_name,compname)==0)
        {
            printf("It is found\n");
            printf("%s",cur->company_name);
            break;

        }
        cur=cur->next;
    }

}
}

void display_designation(node head)
{
    char desig[50];
    printf("Enter the designation of employee\n");
    scanf("%s",desig);
    if(head==NULL)
    {
        printf("LIST is empty\n");
        exit(0);
    }
    if( strcmp(head->designation,desig )==0)
    {
 printf(" the name of employee is %s \n",head->name);
    printf(" the age of employee is %d\n",head->age);
    printf(" the company name of employee is %s\n",head->company_name);
    printf("the salary of employee is %d\n",head->salary);
    printf(" the designation of employee is %s\n",head->designation);
    printf("the employeeID is %d\n ",head->emp_id);
    }
        temp=head;
        while(temp->next!=NULL)
        {

            if(strcmp(temp->designation,desig)==0)
            {

           printf(" the name of employee is %s \n",temp->name);
    printf(" the age of employee is %d\n",temp->age);
    printf(" the company name of employee is %s\n",temp->company_name);
    printf("the salary of employee is %d\n",temp->salary);
    printf(" the designation of employee is %s\n",temp->designation);
    printf("the employeeID is %d\n ",temp->emp_id);
            }
            temp=temp->next;

        }


}

int countdesignation(node head)
{
    char desig[50];
    int count;
    printf("Enter the designation to be counted\n");
    scanf("%s",desig);
    if(head==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    temp=head;
    count=0;
    while(temp!=NULL)
    {
        if(strcmp(temp->designation,desig)==0)
        {
            count++;

        }
        temp=temp->next;
    }
    return count;
}



