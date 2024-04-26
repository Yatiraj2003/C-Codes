#include<stdio.h>
struct player
{
    char name[20];
    float average;
    int ODI_rank;
    int highest_score;
};

void display(char[],float,int);
main()
{
    struct player p1={"virat",59.67,1,183};
    display(p1.name,p1.average,p1.ODI_rank);
}
void display(char name[],float average,int ODI_rank)
{
    printf("%s %f %d",name,average,ODI_rank);
}
