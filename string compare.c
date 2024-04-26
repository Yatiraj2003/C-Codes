#include<stdio.h>
int main()
{
    char s1[100],s2[100];
    int x;
    printf("Enter the string 1 and string 2\n");
    scanf("%s %s",s1,s2);
    x=stringcompare(s1,s2);
    if(x==0)
    {
        printf("Both strings are equal\n");
    }
    else if(x==1)
    {
        printf("string 1 is greater than string 2\n");
    }
    else if(x==-1)
    {
        printf("string 1 is smaller than string 2\n");
    }
    return 0;
}

int stringcompare(char s1[],char s2[])
{
    int i=0;
    while(s1[i]||s2[i])
    {
        if(s1[i]==s2[i])
            i++;
        else if(s1[i]>s2[i])
            return 1;
        else
            return -1;
    }
  return 0;
}
