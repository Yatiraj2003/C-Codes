#include<stdio.h>
 typedef struct book
 {
     char name[20];
     float price;
     int pages;
     int ISBN_no;

 }BK;

 void read(BK b[],int n);
 void display(BK b[],int n);
 void sort(BK b[],int n);
 void search(BK b[],int n);

 int main()

 {
     BK b[12];
     int n;
     printf("Enter the number of books\n");
     scanf("%d",&n);
     read(b,n);
     printf("details are displayed ....\n");
     display(b,n);
     printf("Sorted order based on ISBN number ....\n");
     sort(b,n);
     display(b,n);
     search(b,n);

 }

 void read(BK b[],int n)
 {
     int i;
     for(i=0;i<n;i++)
     {
         printf("Enter book name \n");
         scanf("%s",b[i].name);
         printf("Enter price of book\n");
         scanf("%f",&b[i].price);
         printf("Enter a number of pages in this book\n");
         scanf("%d",&b[i].pages);
         printf("Enter ISBN number of that book\n");
         scanf("%d",&b[i].ISBN_no);
     }
 }



 void display(BK b[],int n)
 {
     int i;
     for(i=0;i<n;i++)
     {
         printf("book name is %s\n",b[i].name);
         printf("price of this book is %f\n",b[i].price);
         printf("no of pages in this book are %d\n",b[i].pages);
         printf("ISBN no of this book  is %d\n",b[i].ISBN_no);

     }
 }

 void sort(BK b[],int n)
 {
     int i,j;
     BK temp;
     for(i=0;i<n;i++)
     {
         for(j=i+1;j<n;j++)
         {
             if(b[i].ISBN_no>b[j].ISBN_no)
             {
                 temp=b[i];
                 b[i]=b[j];
                 b[j]=temp;
             }
         }
     }

 }

 void search(BK b[],int n)
 {
     int i;
     int f=0;
     int ISBN;
     printf("Enter a book with ISBN no to be searched\n");
     scanf("%d",&ISBN);
     for(i=0;i<n;i++)
     {
         if(b[i].ISBN_no==ISBN)
         {
             f=1;

             printf("book name is %s\n",b[i].name);
         printf("price of this book is %f\n",b[i].price);
         printf("no of pages in this book are %d\n",b[i].pages);
         printf("ISBN no of this book  is %d\n",b[i].ISBN_no);
         break;

         }

     }
          if(f==0)
          {
              printf("Record are not found\n");
          }

 }
