#include<stdio.h>
typedef struct info
{
    int highest_score;
    int centuries;
    int ODI_rank;
}IN;

typedef struct cricket_player
{
    char player_name[20];
    char team_name[20];
    float average;
    IN k;

}CP;

void read(CP *p,int );
void display(CP *p,int );
int main()
{
    CP ptr[11];
    int n;
    printf("Enter number of player\n");
    scanf("%d",&n);
    read(ptr,n);
    printf("Displayed as.....\n");
    display(ptr,n);
    return 0;
}

void read(CP *p,int n)
{     for(int i=0;i<n;i++)
{

        printf("Enter your name \n");
        scanf("%s",p->player_name);
        printf("Enter your team name\n");
        scanf("%s",p->team_name);
        printf("Enter batting average\n");
        scanf("%f",&p->average);
        printf("Enter your highest score\n");
        scanf("%d",&p->k.highest_score);
        printf("Enter no of centuries\n");
        scanf("%d",&p->k.centuries);
        printf("Enter ODI rank\n");
        scanf("%d",&p->k.ODI_rank);
        p++;

}


}

void display(CP *p,int n)
{
    int i;
  for( i=0;i<n;i++)
  {
      printf("player name is %s\n",p->player_name);
        printf("team name is %s\n",p->team_name);
        printf("batting average is %f\n",p->average);
        printf("highest score of player is %d\n",p->k.highest_score);
        printf("no of centuries are %d\n",p->k.centuries);
        printf("ODI rank of player is %d\n",p->k.ODI_rank);
        p++;

  }

}

