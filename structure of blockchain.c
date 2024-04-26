#include<stdio.h>
typedef struct Transaction
{
    int trans_id;
    char sender_name[20];
    char reciever_name[20];
    int amount;
    float time;
}TSA;

void read(TSA [],int);
void display(TSA [],int);
void idcompare(TSA [],int);
void usercompare(TSA [],int);

int main()
{
    TSA t[12];
    int n;
    printf("Enter number of transactions\n");
    scanf("%d",&n);
    read(t,n);
    display(t,n);
    idcompare(t,n);
    usercompare(t,n);
    return 0;
}

void read(TSA t[],int n)
{
    int i;
    for( i=0;i<n;i++)
    {
        printf("Enter transaction id \n");
        scanf("%d",&t[i].trans_id);
        printf("Enter sender name \n");
        scanf("%s",t[i].sender_name);
        printf("Enter reciever name \n");
        scanf("%s",t[i].reciever_name);
        printf("Enter amount to be transferred\n");
        scanf("%d",&t[i].amount);
        printf("Enter time to be taken for transaction\n");
        scanf("%f",&t[i].time);
    }
}

void display(TSA t[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Transaction id is %d\n",t[i].trans_id);
        printf("sender name is %s\n",t[i].sender_name);
        printf("Reciever name is %s\n",t[i].reciever_name);
        printf("amount is %d\n",t[i].amount);
        printf("time taken is %f\n",t[i].time);
    }
}

void idcompare(TSA t[],int n)
{
    int id,index=0;
    int i;
    printf("Enter transaction id to be compared\n");
    scanf("%d",&id);
    for(i=0;i<n;i++)
    {
        if(t[i].trans_id==id)
        {
            index=i;
        }
    }
    printf("details are fetched the... details are\n");
    printf("Transaction id is %d\n",t[index].trans_id);
        printf("sender name is %s\n",t[index].sender_name);
        printf("Reciever name is %s\n",t[index].reciever_name);
        printf("amount is %d\n",t[index].amount);
        printf("time taken is %f\n",t[index].time);
}


void usercompare(TSA t[],int n)
{

    int index=0;
    int i;
    char user[20];
    printf("Enter user name to be compared\n");
    scanf("%s",user);
    for(i=0;i<n;i++)
    {
        if(strcmp(t[i].reciever_name,user)==0)
        {
            index=i;
        }
    }
    printf("details are fetched the... details are\n");
    printf("Transaction id is %d\n",t[index].trans_id);
        printf("sender name is %s\n",t[index].sender_name);
        printf("Reciever name is %s\n",t[index].reciever_name);
        printf("amount is %d\n",t[index].amount);
        printf("time taken is %f\n",t[index].time);
}
