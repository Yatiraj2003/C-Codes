#include<stdio.h>
typedef struct movie
{
    char movie_name[20];
    char production[20];
    char director_name[20];
    int release_year;
}MV;

void read(MV m[],int n);
 void display(MV m[],int n);
 void sort(MV m[],int n);
 void compare1(MV m[],int n);
 void compare2(MV m[],int n);



 int main()

 {
     MV m[12];
     int n;
     printf("Enter the number of movies\n");
     scanf("%d",&n);
     read(m,n);
     printf("details are displayed ....\n");
     display(m,n);
     printf("Sorted order based on release year of movie ....\n");
     sort(m,n);
     display(m,n);
     compare1(m,n);
     compare2(m,n);


 }

 void read(MV m[],int n)
 {
     int i;
     for(i=0;i<n;i++)
     {
         printf("Enter movie name \n");
         scanf("%s",m[i].movie_name);
         printf("Enter production house name\n");
         scanf("%s",m[i].production);
         printf("Enter director name of this movie\n");
         scanf("%s",m[i].director_name);
         printf("Enter release year of this movie\n");
         scanf("%d",&m[i].release_year);
     }
 }

 void display(MV m[],int n)
 {
     int i;
     for(i=0;i<n;i++)
     {
         printf("the movie name is %s\n",m[i].movie_name);
         printf("production house name  is %s\n",m[i].production);
         printf("director name is %s\n",m[i].director_name);
         printf("release year of the movie is %d\n",m[i].release_year);

     }
 }

 void sort(MV m[],int n)
 {
     int i,j;
     MV temp;
     for(i=0;i<n;i++)
     {
         for(j=i+1;j<n;j++)
         {
             if(m[i].release_year>m[j].release_year)
             {
                 temp=m[i];
                 m[i]=m[j];
                 m[j]=temp;
             }
         }
     }

 }

 void compare1(MV m[],int n)
 {
     int i;
     int f=0;
     char director[20];
     printf("Enter a director name of the movie\n");
     scanf("%s",director);
     for(i=0;i<n;i++)
     {
         if(strcmp(m[i].director_name,director)==0)
         {
             f=1;
             printf("the movie name is %s\n",m[i].movie_name);
         printf("production house name  is %s\n",m[i].production);
         printf("director name is %s\n",m[i].director_name);
         printf("release year of the movie is %d\n",m[i].release_year);
         break;
         }
     }
     if(f==0)
     {
         printf("Records are not found\n");
     }

 }

 void compare2(MV m[],int n)
 {
     int i;
     int f=0;
     char production_house[20];
     printf("Enter a production house name\n");
     scanf("%s",production_house);
     for(i=0;i<n;i++)
     {
         if(strcmp(m[i].production,production_house)==0)
         {
             f=1;
             printf("the movie name is %s\n",m[i].movie_name);
         printf("production house name  is %s\n",m[i].production);
         printf("director name is %s\n",m[i].director_name);
         printf("release year of the movie is %d\n",m[i].release_year);
         break;
         }
     }
     if(f==0)
     {
         printf("Records are not found\n");
     }


 }







